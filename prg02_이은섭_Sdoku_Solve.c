#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


//매번 실행할때마다 입력하기 귀찮아서 임의로 하나 정해둔것 실제로 실행시 0으로 초기화
int Sdoku[9][9] =
{
	{7,0,2,0,4,8,0,0,0},
	{0,8,5,0,0,0,7,0,0},
	{0,0,0,0,0,2,6,0,3},
	{0,0,0,6,0,1,4,0,2},
	{1,0,8,2,0,0,0,0,7},
	{9,0,0,7,0,0,8,0,0},
	{0,0,0,0,0,3,0,4,1},
	{8,3,0,0,9,0,0,7,0},
	{0,9,0,4,2,0,0,3,0}
};



struct able_POINT
{
	int x, y;
};

struct able_POINT points[81];
int cnt = 0;
bool able_num = true;




void scanf_sdoku(int sdoku[][9]);
void display(int Sdoku[][9]); //스도쿠 화면 띄우는거
void solve_sdoku(int sdoku_origin[][9]);     //빈칸 찾기
void solve_sdoku2(int point_x, int point_y); //가로 판별 
void solve_sdoku3(int point_x, int point_y); //세로 판별
void solve_sdoku4(int point_x, int point_y); //3x3판별





void display(int Sdoku[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Sdoku[i][j] == 0)
			{
				printf("  ");
			}
			else
			{
				printf("%d ", Sdoku[i][j]);
			}



			if ((j + 1) % 3 == 0)
			{
				printf("|");
			}
		}
		if ((i + 1) % 3 == 0)
		{
			printf("\n");
			printf("---------------------");
		}

		printf("\n");

	}

}

void scanf_sdoku(int sdoku[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf_s("%d", &sdoku[i][j]);
		}
	}
};



void solve_sdoku(int sdoku_origin[][9]) //빈 공간의 좌표찾기
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sdoku_origin[i][j] == 0)
			{
				points[cnt].x = i;
				points[cnt].y = j;
				cnt++;
			}
		}
	}
}


void solve_sdoku2(int point_x, int point_y) //가로 판별 
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Sdoku[point_x][point_y] == Sdoku[point_x][j] && point_y != j)
			{
				able_num = false;
				printf("solve2에서 실패\n");

			}
			if (able_num == false)
			{
				break;
			}
		}

		if (able_num == true)
		{
			break;
		}
	}

}

void solve_sdoku3(int point_x, int point_y) //세로 판별
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Sdoku[point_x][point_y] == Sdoku[j][point_y] && point_x != j)
			{
				able_num = false;
				printf("solve3에서 실패\n");
			}

			if (able_num == false)
			{
				break;
			}
		}

		if (able_num == true)
		{
			break;
		}
	}
}



void solve_sdoku4(int point_x, int point_y) //3x3판별
{
	if (point_x < 3)
	{
		if (point_y < 3)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						;						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}


		}

		else if (point_y < 6)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 3; j < 6; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}
		}

		else if (point_y < 9)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 6; j < 9; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}


		}
	}

	else if (point_x < 6)
	{
		if (point_y < 3)
		{
			for (int i = 3; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}


		}

		else if (point_y < 6)
		{
			for (int i = 3; i < 6; i++)
			{
				for (int j = 3; j < 6; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}
		}

		else if (point_y < 9)
		{
			for (int i = 3; i < 6; i++)
			{
				for (int j = 6; j < 9; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}


		}
	}

	else if (point_x < 9)
	{
		if (point_y < 3)
		{
			for (int i = 6; i < 9; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}


		}

		else if (point_y < 6)
		{
			for (int i = 6; i < 9; i++)
			{
				for (int j = 3; j < 6; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}
		}

		else if (point_y < 9)
		{
			for (int i = 6; i < 9; i++)
			{
				for (int j = 6; j < 9; j++)
				{
					if (Sdoku[point_x][point_y] == Sdoku[i][j])
					{
						if ((point_x == i && point_y == j))
						{
							continue;
						}

						able_num = false;
						printf("solve4에서 실패\n");
						if (able_num == false)
						{
							break;
						}
					}
				}
			}


		}
	}
}



int fail_cnt = 0;

int main(void)
{
	printf("이 프로그램은 스도쿠를 풀어드리는 프로그램 입니다.\n");
	printf("풀이를 원하시는 스도쿠의 숫자를 입력해주세요.(빈공간은 0입력)\n");
	//scanf_sdoku(Sdoku);
	solve_sdoku(Sdoku);

	system("cls");
	display(Sdoku);
	printf("\n\n");


	printf("%d\n", cnt);


	int save = 0;
	int i = 0;
	Sdoku[points[save].x][points[save].y] = 1;
	fail_cnt = 0;
	//이부분부터 밑에까지 함수로 또만들거임
	while (save < cnt && save >= 0)
	{
		printf("==================================\n");
		printf("save = %d\n", save);
		printf("Sdoku[%d][%d] = %d\n\n", points[save].x, points[save].y, Sdoku[points[save].x][points[save].y]);

		able_num = true;


		solve_sdoku2(points[save].x, points[save].y);

		if (able_num == true)
		{
			solve_sdoku3(points[save].x, points[save].y);
		}

		if (able_num == true)
		{
			solve_sdoku4(points[save].x, points[save].y);
		}


		if (able_num == true)//<- 이게 트루라는 것은 후보숫자로 가능하던거
		{
			display(Sdoku);

			if (save == cnt - 1)
			{
				break;
			}

			else
			{
				save++;
				printf("save = %d\n", save);
				Sdoku[points[save].x][points[save].y] = 1;
				printf("Sdoku[%d][%d] = %d\n\n", points[save].x, points[save].y, Sdoku[points[save].x][points[save].y]);
			}

		}

		else if (able_num == false)  //실패할 경우 위에거가 실행안되고 여기로옴 
		{

			if (Sdoku[points[save].x][points[save].y] == 9)
			{
				display(Sdoku);

				Sdoku[points[save].x][points[save].y] = 0;
				save--;

				if (Sdoku[points[save].x][points[save].y] == 9)
				{
					Sdoku[points[save].x][points[save].y] = 0;
					save--;
					Sdoku[points[save].x][points[save].y]++;
				}

				else
				{
					Sdoku[points[save].x][points[save].y]++;
				}

			}

			else
			{
				display(Sdoku);

				printf("save = %d\n", save);
				Sdoku[points[save].x][points[save].y]++;
				printf("Sdoku[%d][%d] = %d\n\n", points[save].x, points[save].y, Sdoku[points[save].x][points[save].y]);
			}



		}


	}
	//여기까지는 따로 뽑아서 함수로 만들어야 main이 깔끔함


	system("cls");
	display(Sdoku);


	return 0;
}