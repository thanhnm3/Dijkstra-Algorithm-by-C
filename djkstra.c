#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9                                     // V là số điểm trên đồ thị

#define MAX INT_MAX                             // Chọn MAX là vô cùng lớn

int minDistance(int dist[], bool sptSet[])      // Hàm minDistance để tìm khoảng cách ngắn nhất từ tập hợp các 
{                                               // đỉnh
   int min = MAX, min_index;                    // Tạo giá trị nhỏ nhất bằng vô cùng

   for (int v = 0; v < V; v++)                  // Duyệt qua lần lượt các đỉnh, trả về min_index là đỉnh có 
     if (sptSet[v] == false && dist[v] <= min)  // khoảng cách nhỏ nhất.
         min = dist[v], min_index = v;
 
   return min_index;
}
 
void printSolution(int dist[], int n)           // Hàm in kết quả, trả về khoảng cách nhỏ nhất từ đỉnh 
{                                               // nguồn tới tất cả các đỉnh khác
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
 
void dijkstra(int graph[V][V], int src)         // Thực hiện hàm Dijkstra với dữ liệu vào là ma trận kề
{
     int dist[V];                               // mảng dist[] để kết quả cuối cùng về khoảng cách
     bool sptSet[V];                            // sptSet[] để dạng bool để xem đã duyệt đỉnh hay chưa
                                                // true nếu đã duyệt và false nếu chưa duyệt
     for (int i = 0; i < V; i++)                // Khởi tạo mọi khoảng cách là vô cùng và tất cả là chưa duyệt
        dist[i] = MAX, sptSet[i] = false;
 
     dist[src] = 0;                             // Khoảng cách từ nguồn tới chính nó = 0
 
     for (int count = 0; count < V-1; count++)  // Chọn một điểm có khoảng cách nhỏ nhất mà chưa duyệt
     {
       int u = minDistance(dist, sptSet);
 
       sptSet[u] = true;                        // Đánh dấu điểm đó lầ đã duyệt
 
       for (int v = 0; v < V; v++)              // Cập nhật giá trị dist cho đỉnh liền kề
 
         if (!sptSet[v] && graph[u][v] && dist[u] != MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];    // Chỉ cập nhật dist[v] khi có một cạnh từ u đến v và tổng
     }                                          // trọng số từ nguồn đến v đi qua u là nhỏ hơn dist[v] hiện có
 
     printSolution(dist, V);                    // In kết quả
}
 
int main()
{
   int graph[V][V] = {{0, 20, 0, 0, 0, 0, 0, 8, 0},
                      {20, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
   
 
    return 0;

}
