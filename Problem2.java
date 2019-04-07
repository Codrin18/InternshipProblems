import java.util.*; 
  
class G{ 
  
    // The main function that prints the  
    // arrangement with the largest value. 
    // The function accepts a vector of strings     
    static void printLargest(Vector<String> arr){ 
      
        Collections.sort(arr, new Comparator<String>(){ 
  
        // A comparison function which is used by  
        // sort() in printLargest() 
        @Override
        public int compare(String X, String Y) { 
          
        // first append Y at the end of X 
        String XY=X + Y; 
          
        // then append X at the end of Y 
        String YX=Y + X; 
          
        // Now see which of the two formed numbers  
        // is greater 
        return XY.compareTo(YX) > 0 ? -1:1; 
    } 
    }); 
          
    Iterator it = arr.iterator(); 
  
    while(it.hasNext()) 
        System.out.print(it.next()); 
      
    } 
      
    public static void main (String[] args) { 
          
        Vector<String> arr; 
        arr = new Vector<>(); 
         
        arr.add("3"); 
        arr.add("30"); 
        arr.add("34"); 
        arr.add("5");
      	arr.add("9");
        printLargest(arr); 
    } 
} 

// This is the optimal solution with :
// Time complexity: O(nlogn)
// Space complexity : O(1)
					
					