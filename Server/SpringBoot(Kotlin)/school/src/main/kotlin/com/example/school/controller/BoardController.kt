package com.example.school.controller

import com.example.school.dto.BoardDTO
import org.springframework.stereotype.Controller
import org.springframework.ui.Model
import org.springframework.web.bind.annotation.RequestMapping
import java.util.*

@Controller
class BoardController {
    @RequestMapping("/list")
    fun list(model: Model): String {
        val board = BoardDTO(
            num = 0,
            title = "게시판 연습",
            writer = "관리자",
            date = Date(),
            count = 0
        )
        val list = listOf(board, board, board)
        model.addAttribute("list", board)
        return "board/list"
    }
}