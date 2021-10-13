package com.example.retrofit.model

import java.io.Serializable

data class Photo (var thumnail: String?, var author: String?, var createAt: String?, var likeCount: Int?): Serializable{

}