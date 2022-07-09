package com.example.study_board.domain.user;

import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface UserRepository extends JpaRepository<Client, Long> {
    Optional<Client> findByEmail(String email);
}
