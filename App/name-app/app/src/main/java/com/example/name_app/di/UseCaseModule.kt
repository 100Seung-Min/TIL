package com.example.name_app.di

import com.example.data.usecase.CheckLoveCalculatorUseCase
import com.example.domain.repository.MainRepository
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import javax.inject.Singleton

@Module
@InstallIn(SingletonComponent::class)
class UseCaseModule {
    @Provides
    @Singleton
    fun provideCheckLoveCalculatorMainUseCase(repository: MainRepository) = CheckLoveCalculatorUseCase(repository)
}