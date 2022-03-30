package com.example.presentation.view

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.activityViewModels
import androidx.navigation.fragment.findNavController
import com.example.domain.utils.ErrorType
import com.example.domain.utils.ScreenState
import com.example.presentation.R
import com.example.presentation.base.BaseFragment
import com.example.presentation.databinding.FragmentManNameBinding
import com.example.presentation.viewmodel.MainViewModel

class ManNameFragment : BaseFragment<FragmentManNameBinding>(R.layout.fragment_man_name) {
    private val mainViewModel by activityViewModels<MainViewModel>()
    override fun init() {
        binding.fragment = this
        observeViewModel()
    }

    fun nextBtnClick(view: View){
        binding.loadingBar.visibility = View.VISIBLE
        mainViewModel.manNameResult = binding.editNameTxt.text.toString()
        mainViewModel.checkLoveCalculator("love-calculator.p.rapidapi.com", "8dd1ea94bbmshce6ac5fda12934cp1b67e5jsn429603211372", mainViewModel.manNameResult, mainViewModel.womanNameResult)
    }

    private fun observeViewModel(){
        binding.loadingBar.visibility = View.GONE
        mainViewModel.apiCallEvent.observe(this){
            when(it){
                ScreenState.LOADING -> this.findNavController().navigate(R.id.action_manNameFragment_to_resultFragment)
                ScreenState.ERROR -> toastErrorMeasge()
                else -> shortShowToast("알 수 없는 오류가 발생했습니다")
            }
        }
    }

    private fun toastErrorMeasge(){
        when(mainViewModel.apiErrorType){
            ErrorType.NETWORK -> longShowToast("네트워크 오류가 발생했습니다")
            ErrorType.SESSION_EXPIRED -> longShowToast("세션이 만료되었습니다")
            ErrorType.TIMEOUT -> longShowToast("호출시간이 초과되었습니다")
            ErrorType.UNKNOWN -> longShowToast("예기치 못한 오류가 발생했습니다")
        }
    }
}