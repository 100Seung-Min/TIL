package com.example.name_app.di

import com.example.data.remote.api.LoveCalculatorAPI
import com.example.data.repository.remote.datasource.MainDataSource
import com.example.data.repository.remote.datasourceImpl.MainDataSourceImpl
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import javax.inject.Singleton

@Module
@InstallIn(SingletonComponent::class)
class DataSourceModule {
    @Provides
    @Singleton
    fun provideMainDataSource(
        loveCalculatorAPI: LoveCalculatorAPI
    ): MainDataSource{
        return MainDataSourceImpl(
            loveCalculatorAPI
        )
    }
}