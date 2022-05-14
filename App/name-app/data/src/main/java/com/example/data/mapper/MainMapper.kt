package com.example.data.mapper

import com.example.domain.model.DomainLoveResponse

object MainMapper {
    fun loveMapper(
        dataResponse: DomainLoveResponse?
    ): DomainLoveResponse?{
        return if (dataResponse != null){
            DomainLoveResponse(
                fname = dataResponse.fname,
                sname = dataResponse.sname,
                percentage = dataResponse.percentage,
                result = dataResponse.result
            )
        } else dataResponse
    }
}