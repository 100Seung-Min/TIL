package com.example.data.usecase

import com.example.domain.model.DomainLoveResponse
import com.example.domain.repository.MainRepository
import com.example.domain.utils.RemoteErrorEmitter
import javax.inject.Inject

class CheckLoveCalculatorUseCase @Inject constructor(
    private val mainRepository: MainRepository
) {
    suspend fun execute(
        errorEmitter: RemoteErrorEmitter,
        key: String,
        host: String,
        mName: String,
        wName: String
    ) = mainRepository.checkLoveCalculator(errorEmitter, key, host, mName, wName)
}