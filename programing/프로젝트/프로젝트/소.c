printf("\n\n\n\n        ┌────────────────────┐\n");
printf("        │                    │\n");
printf("        │                    │\n");
printf("        │                    │\n");
printf("        │                    │\n");
printf("        │                    │\n");
printf("        │                    │\n");
printf("        │                    │\n");
printf("        │                    │\n");
printf("        └────────────────────┘\n");
Score = 0;
for (;;)
{
	gotoxy(x - 2, y);
	printf("> 쉬움");
	gotoxy(x, y + 1);
	printf("보통");
	gotoxy(x, y + 2);
	printf("어려움");
	gotoxy(x, y + 3);
	printf("매우 어려움");
	gotoxy(x, y + 4);
	printf("뒤로가기");
	gotoxy(x, y + 5);
	printf("종료하기");