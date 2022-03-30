package com.example.presentation.view

import android.view.View
import androidx.fragment.app.activityViewModels
import androidx.navigation.fragment.findNavController
import com.example.presentation.R
import com.example.presentation.base.BaseFragment
import com.example.presentation.databinding.FragmentResultBinding
import com.example.presentation.viewmodel.MainViewModel

class ResultFragment : BaseFragment<FragmentResultBinding>(R.layout.fragment_result) {
    private val mainViewModel by activityViewModels<MainViewModel>()
    override fun init() {
        binding.fragment = this
        initResult()
    }

    private fun initResult(){
        binding.score.text = mainViewModel.apiCallResult.percentage.toString()
        when(mainViewModel.apiCallResult.percentage){
            in 0..20 -> setLoveMsgTxt("당장 헤어지세요")
            in 21..40 -> setLoveMsgTxt("거리감이 느껴지네요")
            in 41..70 -> setLoveMsgTxt("그저 친구사이")
            in 71..90 -> setLoveMsgTxt("어느새 연인으로..?")
            in 91..99 -> setLoveMsgTxt("오늘부터 1일")
            100 -> setLoveMsgTxt("빨리 결혼 하세요")
            else -> setLoveMsgTxt("삐빅 측정 불가")
        }
    }

    private fun setLoveMsgTxt(msg: String){
        binding.message.text = msg
    }

    fun backMainBtnClick(view: View){
        this.findNavController().navigate(R.id.action_resultFragment_to_mainFragment)
    }
}