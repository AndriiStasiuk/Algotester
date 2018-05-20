import java.util.Scanner;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int k = sc.nextInt();


        BigInteger[][] matrix = new BigInteger[N][M];
        int array[] = new int[2*k];

        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("1");
        BigInteger c = new BigInteger("-1");


        for (int i = 0; i < 2*k; i++) {
            array[i] = sc.nextInt();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = c;
            }
        }

        for(int i = 0; i < 2*k; i += 2){
            matrix[array[i] - 1][(array[i+1]-1)] = a;
        }

        for (int i = 0; i < M ; i++){
            if(matrix[0][i] != a){
                matrix[0][i] = b;
            }
            if((matrix[0][i] == a) && (i < (M-1)) ){
                matrix[0][i+1] = a;
            }
        }

        for (int i = 0; i < N; i++){
            if(matrix[i][0] != a){
                matrix[i][0] = b;
            }
            if((matrix[i][0] == a) && (i < (N-1)) ){
                matrix[i+1][0] = a;
            }
        }

        if((N == 1 || M == 1) && k == 1){
            System.out.println("0");
            return;
        }

        for (int i = 1; i < N; i++){
            for(int j = 1; j < M; j++){
                if(matrix[i][j]!=b){
                    matrix[i][j] = matrix[i-1][j-1].add(matrix[i-1][j].add(matrix[i][j-1]));
                }
            }
        }

        System.out.println(matrix[N-1][M-1]);

    }
}
