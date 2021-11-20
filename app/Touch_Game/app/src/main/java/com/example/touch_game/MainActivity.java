package com.example.touch_game;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

import com.example.touch_game.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    ActivityMainBinding binding;
    int count = 10;
    int power = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.countTouchTxt.setText(String.valueOf(count));

        binding.touchImg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                count -= power;
                if(count == -1){
                    count = 10;
                }
                binding.countTouchTxt.setText(String.valueOf(count));
            }
        });
    }
}