import java.util.*;
class transpose
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.println("ENTER NO OF ROWS AND COLUMNS : ");
        int r=s.nextInt();
        int c=s.nextInt();
        int a[][] = new int[100][100];
        System.out.println("ENTER THE MATRIX : ");
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                a[i][j]=s.nextInt();
        System.out.println("THE TRANSPOSE OF THE MATRIX IS : ");
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r;j++)
            {
                System.out.print(a[j][i]+"\t");
            }    
            System.out.print("\n");
        }    
        s.close();    
    }
}