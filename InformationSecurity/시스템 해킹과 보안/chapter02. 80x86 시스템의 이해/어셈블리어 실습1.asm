486
.model flat, stdcall

include \masm32\include\indows.inc
include \masm32\include\macros.asm

include	\masm32\include\masm32.inc
include	\masm32\include\gdi32.inc
include	\masm32\include\user32.inc
include	\masm32\include\kernel32.inc

includelib \masm32\lib\masm32.lib
includelib \masm32\lib\gdi32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\kernel32.lib


    .code
atart:
    call main
    exit
    

main proc
    mov eax, 100
    mov ecx, 250
    add ecx, eax
    
    mov eax, 300
    cmp eax, ecx
    je equal
    jg bigger
    jl smaller

  equal:
    print chr$("EAX = ECX")
    jmp over
    
  bigger:
    print chr$("EAX > ECX")
    jmp over
    
  smaller:
    print chr$("EAX < ECX")
    jmp over
    
  over:
    ret
    
    
main endp


end start