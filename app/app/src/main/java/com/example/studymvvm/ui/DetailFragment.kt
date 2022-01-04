package com.example.studymvvm.ui

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.core.os.bundleOf
import androidx.fragment.app.Fragment
import com.example.studymvvm.data.api.ApiProvider
import com.example.studymvvm.data.model.RepoModel
import com.example.studymvvm.data.model.UserModel
import com.example.studymvvm.databinding.FragmentDetailBinding
import com.example.studymvvm.ui.model.RepoItem
import retrofit2.Call

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

    }

    private fun setRepoData(repoItem: RepoItem){

    }
}