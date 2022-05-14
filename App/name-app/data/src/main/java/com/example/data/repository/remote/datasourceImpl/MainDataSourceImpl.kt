package com.example.data.repository.remote.datasourceImpl

import com.example.domain.model.DomainLoveResponse
import com.example.data.remote.api.LoveCalculatorAPI
import com.example.data.repository.remote.datasource.MainDataSource
import com.example.data.utils.base.BaseDataSource
import com.example.domain.utils.RemoteErrorEmitter
import javax.inject.Inject

class MainDataSourceImpl @Inject constructor(
    private val loveCalculatorAPI: LoveCalculatorAPI
): BaseDataSource(), MainDataSource {
    override suspend fun checkLoveCalculator(
        errorEmitter: RemoteErrorEmitter,
        host: String,
        key: String,
        mName: String,
        wName: String
    ): DomainLoveResponse? {
        return safeApiCall(errorEmitter){
            loveCalculatorAPI.getPercentage(host = host, key = key, fName = mName, sName = wName)
        }?.body()
    }
}