package com.example.studymvvm.ui

import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.core.os.bundleOf
import androidx.fragment.app.Fragment
import com.bumptech.glide.Glide
import com.example.studymvvm.data.api.ApiProvider
import com.example.studymvvm.data.model.RepoModel
import com.example.studymvvm.data.model.UserModel
import com.example.studymvvm.data.model.mapToPresentation
import com.example.studymvvm.databinding.FragmentDetailBinding
import com.example.studymvvm.ui.model.RepoItem
import com.example.studymvvm.ui.model.UserItem
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

class DetailFragment: Fragment() {
    companion object {
        private const val ARGUMENT_OWNER_NAME = "owner_name"

        private const val ARGUMENT_REPO = "repo"

        fun newInstance(ownerName: String, repoName: String) = DetailFragment().apply {
            arguments = bundleOf(
                Pair(ARGUMENT_OWNER_NAME, ownerName),
                Pair(ARGUMENT_REPO, repoName)
            )
        }
    }

    private val userApi = ApiProvider.provideUserApi()

    private var userCall: Call<UserModel>? = null

    private val repoApi = ApiProvider.provideRepoApi()

    private var repoCall: Call<RepoModel>? = null

    private var binding: FragmentDetailBinding? = null

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = FragmentDetailBinding.inflate(inflater, container, false)
        return binding!!.root
    }

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
        val ownerName = arguments?.getString(ARGUMENT_OWNER_NAME) ?: throw IllegalArgumentException(
            "No owner name info exists in extras"
        )

        val repo = arguments?.getString(ARGUMENT_REPO) ?: throw java.lang.IllegalArgumentException(
            "No repo info exists in extras"
        )

        loadData(ownerName, repo)
    }

    private fun loadData(ownerName: String, repo: String){
        hideError()
        showProgress()
        loadRepoData(ownerName, repo)
        loadUserData(ownerName)
    }

    private fun loadRepoData(ownerName: String, repo: String){
        repoCall = repoApi.getRepository(ownerName, repo)
        repoCall?.enqueue(object : Callback<RepoModel>{
            override fun onResponse(call: Call<RepoModel>, response: Response<RepoModel>) {
                hideProgress()

                val body = response.body()
                if(response.isSuccessful && body != null){
                    setRepoData(body.mapToPresentation(requireContext()))
                } else{
                    showError(response.message())
                }
            }

            override fun onFailure(call: Call<RepoModel>, t: Throwable) {
                hideProgress()
                showError(t.message)
            }
        })
    }

    private fun setRepoData(repoItem: RepoItem){
        Glide.with(requireContext())
            .load(repoItem.owner.ownerUrl)
            .placeholder(ColorDrawable(Color.GRAY))
            .error(ColorDrawable(Color.RED))
            .into(binding!!.ivProfile)
        binding!!.tvTitle.text = repoItem.title
        binding!!.tvStars.text = repoItem.stars
        binding!!.tvDescription.text = repoItem.description
        binding!!.tvLanguage.text = repoItem.language
    }

    private fun loadUserData(userName: String){
        userCall = userApi.getUser(userName)
        userCall?.enqueue(object : Callback<UserModel>{
            override fun onResponse(call: Call<UserModel>, response: Response<UserModel>) {
                hideProgress()

                val body = response.body()
                if(body != null && response.isSuccessful){
                    setUserData(body.mapToPresentation(requireContext()))
                } else {
                    showError(response.message())
                }
            }

            override fun onFailure(call: Call<UserModel>, t: Throwable) {
                showError(t.message)
            }
        })
    }

    private fun setUserData(userItem: UserItem){
        binding!!.tvFollower.text = userItem.followers
        binding!!.tvFollowing.text = userItem.following
    }

    private fun showError(message: String?){
        with(binding!!.tvMessage){
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

    private fun showProgress(){
        binding!!.tvMessage.visibility = View.GONE
        binding!!.pbLoading.visibility = View.VISIBLE
    }

    private fun hideProgress(){
        binding!!.pbLoading.visibility = View.GONE
    }

    override fun onStop() {
        repoCall?.cancel()
        userCall?.cancel()
        super.onStop()
    }
}