#include <stdio.h>
int main()
{
        int high, low, highestDay, lowestDay, days, day, i;
        int highest = -40;
        int lowest = 40;
        int period = 0;
        float meanLow, meanHigh, meanTemp;
        
        printf("\n---=== IPC Temperature Analyzer ===---");
                printf("Please enter the number of days, between 3 and 10, inclusive: ");
                scanf("%d", &days);
                while (!(days >= 3 && days <= 10))
                        {
                                printf("\nInvalid entry, please enter the number of days, between 3 and 10, inclusive: ");
                                scanf("%d", &days);

                        }
                int highs[days], lows[days];
                
                for (day=1; day < days+1; ++day)
                {
                       
                        printf("Day %d - High: ", day);
                        scanf("%d", &highs[day-1]);
                
                        printf("Day %d - Low: ", day);
                        scanf("%d", &lows[day-1]);

                        
                        
                        while (lows[day-1] < -40 || highs[day-1] > 40 || highs[day-1] < lows[day-1] )
                        {
                                printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low \n");
                                printf("Day %d - High:", day);
                                scanf("%d", &highs[day-1]);

                                printf("Day %d - Low:", day);
                                scanf("%'d", &lows[day-1]); 
              
                        }    

                       
                        if (highs[day-1] > highest)
                        {
                                highest = highs[day-1];
                                highestDay = day;
                        }
                        if (lows[day-1] < lowest)
                        {
                                lowest = lows[day-1];
                                lowestDay = day;
                        }
                       
                }
                
                // Loop through the highs and lows arrays to create a table of values
                printf("\nDay\tHi\tLow"); 
                for (day=1; day<days+1; day++)
                        printf("\n%d\t%d\t%d", day, highs[day-1], lows[day-1]);

                printf("\n\nThe highest temperature was: %d, on day %d",highest, highestDay);
                printf("\nThe lowest temperature was: %d, on day %d\n",lowest, lowestDay);

                // Loop through prompt until user enters -1
                while (period > -1){

                        printf("\nEnter a number betwen 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
                        scanf("%d", &period);
                        float lowTotal = 0;
                        float highTotal = 0;
                         // Display error message and reprompt    
                        while(!(period <= days && period != 0)){
                                printf("\nInvalid entry, please enter a number between betwen 1 and %d, inclusive: ", days);
                                scanf("%d", &period);

                        }      
                        // sum the array values and find their means
                        for (i=1; i<period+1;i++){
                                lowTotal = lowTotal + lows[i-1]; 
                                highTotal = highTotal + highs[i-1]; 

                                meanLow = lowTotal/period;
                                meanHigh = highTotal/period;

                                meanTemp = (meanLow+meanHigh)/2;
                        }
                        if (period <= -1){
                                printf("\nGoodbye!\n");
                                break;
                        }
                        printf("The average temperature up to day %d is: %0.2f\n", period, meanTemp);                                          
                }      
        return 0;
}
