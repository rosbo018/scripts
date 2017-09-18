import java.util.*;
class qsortA{

        public static float sortTime(int size){
                int[] arr = new int[size];
                Random r = new Random();
                for (int i = 0; i< size; i++){
                        arr[i] = size-i;
                }
                long start =  System.nanoTime();
                Arrays.sort(arr);
                long time = System.nanoTime()- start;
                return time;
        }
        public static void main(String[] args){
                float[] times = new float[100];
                float timesbase = sortTime(1000000);
                for (int i = 2; i < 100; i +=1){
                        times[i] = sortTime(i*1000000);
                        System.out.println(i+ " : " + times[i]/timesbase);
                }
        }

}
