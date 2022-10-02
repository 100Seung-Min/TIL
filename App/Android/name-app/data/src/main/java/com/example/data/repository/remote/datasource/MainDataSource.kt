package com.example.data.repository.remote.datasource

import com.example.domain.model.DomainLoveResponse
import com.example.domain.utils.RemoteErrorEmitter

interface MainDataSource {
    suspend fun checkLoveCalculator(
        errorEmitter: RemoteErrorEmitter,
        host: String,
        key: String,
        mName: String,
        wName: String
    ) : DomainLoveResponse?
}