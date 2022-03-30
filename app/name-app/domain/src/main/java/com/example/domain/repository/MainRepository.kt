package com.example.domain.repository

import com.example.domain.model.DomainLoveResponse
import com.example.domain.utils.RemoteErrorEmitter

interface MainRepository {
    suspend fun checkLoveCalculator(
        errorEmitter: RemoteErrorEmitter,
        key: String,
        host: String,
        mName: String,
        wName: String
    ): DomainLoveResponse?
}