package com.example.studymvvm.ui

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.Fragment
import com.example.githubapi.databinding.FragmentSearchBinding
import com.example.studymvvm.data.api.ApiProvider
import com.example.studymvvm.data.model.mapToPresentation
import com.example.studymvvm.ui.adapter.RepositoryAdapter
import com.example.studymvvm.data.model.RepoSearchResponse
import com.example.studymvvm.utils.AppUtils
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

class SearchFragment: Fragment() {
    companion object{
        fun newInstance() = SearchFragment()
    }

    private val repoAdapter by lazy {
        RepositoryAdapter().apply {
            onItemClick = {
                (requireActivity() as MainActivity).goToDetailFragment(
                    it.owner.ownerName,
                    it.repoName
                )
            }
        }
    }

    private val repoApi = ApiProvider.provideRepoApi()

    private var repoCall: Call<RepoSearchResponse>? = null

    private var binding: FragmentSearchBinding? = null

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding =  FragmentSearchBinding.inflate(inflater, container, false)
        return binding!!.root
    }

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)

        initRecyclerView()
        initEditText()
        initButton()
    }

    private fun initRecyclerView(){
        binding!!.listSearchRepository.adapter = repoAdapter
    }

    private fun initEditText(){

    }

    private fun initButton(){
        binding!!.btnSearch.setOnClickListener{
            val query = binding!!.etSearch.text.toString()
            searchRepository(query)
        }
    }

    private fun searchRepository(query: String){
        if(query.isEmpty()){
            Toast.makeText(requireContext(), "please write repository name", Toast.LENGTH_SHORT).show()
        } else {
            hideKeboard()
            clearResults()
            hideError()
            showProgress()

            repoCall = repoApi.searchRepositories(query)
            repoCall?.enqueue(object : Callback<RepoSearchResponse>{
                override fun onResponse(
                    call: Call<RepoSearchResponse>,
                    response: Response<RepoSearchResponse>
                ) {
                    hideProgress()
                    val body = response.body()
                    if(response.isSuccessful && null != body){
                        with(repoAdapter) {
                            setItems(body.items.map{it.mapToPresentation(requireContext())})
                        }
                        if(0 == body.totalCount){
                            showError("No search result.")
                        }
                    } else {
                        showError(response.message())
                    }
                }

                override fun onFailure(call: Call<RepoSearchResponse>, t: Throwable) {
                    hideProgress()
                    showError(t.message)
                }
            })
        }
    }

    private fun hideKeboard(){
        AppUtils.hideSoftKeyBoard(requireActivity())
    }

    private fun clearResults(){
        repoAdapter.clearItems()
    }

    private fun showProgress(){
        binding!!.pbLoading.visibility = View.VISIBLE
    }

    private fun hideProgress(){
        binding!!.pbLoading.visibility = View.GONE
    }

    private fun showError(message: String?){
        with(binding!!.tvMessage) {
            text = message ?: "Unexpected Error"
            visibility = View.VISIBLE
        }
    }

    private fun hideError(){
        with(binding!!.tvMessage){
            text = ""
            visibility = View.GONE
        }
    }

    override fun onStop() {
        repoCall?.cancel()
        super.onStop()
    }
}