/*
 package Fenzhi;

import java.util.Scanner;

public class Tch extends per{

	public int year,monuth,day;


	public Tch()
	{

	}

	public void GetTime()
	{
		System.out.println("输入年月日以‘-’分隔，年份<10000：");
		Scanner stdin = new Scanner(System.in);
		String stime = stdin.next();
		String sday="",smonuth="",syear="";

		int si=0;
		for(int i=si;i<stime.length();i++)
		{
			if(stime.charAt(i)=='-')
			{
				si=i+1;
				break;
			}
			else
			{
				syear = syear + stime.charAt(i);
			}
		}

		for(int i=si;i<stime.length();i++)
		{
			if(stime.charAt(i)=='-')
			{
				si=i+1;
				break;
			}
			else
			{
				smonuth = smonuth + stime.charAt(i);
			}
		}

		for(int i=si;i<stime.length();i++)
		{
			if(stime.charAt(i)=='-')
			{
				si=i+1;
				break;
			}
			else
			{
				sday = sday + stime.charAt(i);
			}
		}



		year=Integer.parseInt(syear);
		monuth=Integer.parseInt(smonuth);
		day=Integer.parseInt(sday);
		System.out.println(year + " " + monuth + " " + day);

	}

	public void gettest()
	{
		int md[],Allday=0,iruntag=0;
		md = new int[13];
		md[1]=31;
		md[2]=28;
		md[3]=31;
		md[4]=30;
		md[5]=31;
		md[6]=30;
		md[7]=31;
		md[8]=31;
		md[9]=30;
		md[10]=31;
		md[11]=30;
		md[12]=31;

		if(year>=10000 || (monuth<1||monuth>12) ||(day<1||day>31) )
		{
			System.out.println("年份有误");

			}
		else
		{
			if(year%400 == 0)
			{
				iruntag=1;
			}
			else if((year%4 == 0)&&(year%100 != 0))
			{
				iruntag=1;
			}

			if(monuth<1||monuth>12)
			{
				System.out.println("月份有误");

			}
			else
			{
				for(int i=1 ;i<monuth;i++)
					Allday= Allday + md[i];

				if(monuth>=3)
					Allday=Allday+iruntag;

				if(day<1||day>md[monuth])
				{
					System.out.println("天数有误");

				}
				else
				{
					Allday=Allday+day;
					System.out.println(year + "-" + monuth + "-" + day +" is the No."+ Allday +" day of "+year);
				}

			}
		}

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tch t = new Tch();
		t.GetTime();
		t.gettest();
	}




}*/

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    //2000-2-28
    int year,month,day;

    //cin >> year >> "-" >> month >> "-" >>day;

    scanf("%d-%d-%d",&year,&month,&day);
    /*
    cout << year << endl;
    cout << month << endl;
    cout << day << endl;
     */

    /*
    int md[13],Allday=0,iruntag=0;
    md[1]=31;
    md[2]=28;
    md[3]=31;
    md[4]=30;
    md[5]=31;
    md[6]=30;
    md[7]=31;
    md[8]=31;
    md[9]=30;
    md[10]=31;
    md[11]=30;
    md[12]=31;

    if(year>=10000 || (month<1||month>12) ||(day<1||day>31) ) {
        cout << "年份有误" <<endl;
    }else{
        if(year%400 == 0)
        {
            iruntag=1;
        }
        else if((year%4 == 0)&&(year%100 != 0))
        {
            iruntag=1;
        }

        if(month<1||month>12) {
            cout << "月份有误" <<endl;
        }else {
            for(int i=1 ;i<month;i++)
                Allday= Allday + md[i];

            if(month>=3)
                Allday=Allday+iruntag;

            if(day<1||day>md[month]) {
               cout <<"天数有误"<<endl;
            } else {
                Allday=Allday+day;
                cout << year << "-" <<  month <<  "-" << day  << " is the No."<< Allday <<" day of "<<year << endl;
            }

        }
    }
     */








    int md[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int allday=0;
    if(year>=10000 || (month<1||month>12) ||(day<1||day>31) ) {
        cout << "invalid input" <<endl;
    }else{
        if(month<1||month>12) {
            cout << "invalid input" <<endl;
        }else{
            //考虑当月天数
            // md[month-1] day
            if(day > md[month-1] || day < 1){
                cout << "invalid input" <<endl;
            }else{
                if(year%400 == 0) {
                    //闰年 2月 29天 -> 1
                    md[1] = 29;
                }

                for(int i = 0 ;i < month-1;i++){
                    allday += md[i];
                }
                allday += day;
                cout << year << "-" <<  month <<  "-" << day  << " is the No."<< allday <<" day of "<<year << endl;
            }


        }

    }
    return 0;
}