#include <stdio.h>

typedef struct queuq
{
	int x; //세로 
	int y; //가로 
}queuq;

int n, m, cnt;
int map[105][105];

int fr, rr;

int vi[105][105];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

queuq q[10005];

void push(int x, int y)
{
	rr++;
	q[rr].x = x;
	q[rr].y = y;
}

void bfs()
{
	
	while(fr < rr) // 큐 프론트카 리어가 될때까지 반복
	{
		fr++;  //프론트 +1
		for(int i = 0; i < 4; i++){   

			int nx = q[fr].x + dx[i];
			int ny = q[fr].y + dy[i];
			
			if(nx >= 1 && ny >= 1 && nx <= n && ny <= m){



				if(map[nx][ny] == 1 && vi[nx][ny] == 0){
					push(nx, ny);
					vi[nx][ny] = vi[q[fr].x][q[fr].y] + 1;


				}
			}
		}
	}
}

int main(void)
{
	
	
	scanf("%d %d", &n, &m);//n m 입력

	for(int i = 1; i <= n; i++)  // 반복문을 통해 입력 받음
		for(int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);;


    //초기화
	
	push(1, 1);

	vi[1][1] = 1;
	
	bfs();
	
	printf("%d", vi[n][m]);
	
	return 0;
}