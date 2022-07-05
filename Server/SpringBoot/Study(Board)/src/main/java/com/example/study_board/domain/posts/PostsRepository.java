package com.example.study_board.domain.posts;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

public interface PostsRepository extends JpaRepository<Posts, Long> {
    @Query("SELECT p from Posts p order by p.id DESC")
    List<Posts> findAllDesc();
}
