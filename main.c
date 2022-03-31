#include <stdio.h>

void price_demand();
void price_supply();
void income_demand();
void cross_demand();
void maximize_budget();
int main() {
    int input;
    char rotate[2] ;rotate[0]='y';
    while (rotate[0]=='y') {
        printf("Do you want to know?\n");
        printf("----Price elasticity of demand and Total Revenue (Enter 1)\n");
        printf("----Price elasticity of supply (Enter 2)\n");
        printf("----Income elasticity of demand (Enter 3)\n");
        printf("----Cross elasticity of demand (Enter 4)\n");
        printf("----Available budget to maximize (Enter 5)\n");
        printf("\nENTER YOUR CHOICE :");
        scanf("%d", &input);

        if (input == 1)
            price_demand();
        else if (input == 2)
            price_supply();
        else if (input == 3)
            income_demand();
        else if (input == 4)
            cross_demand();
        else if (input == 5)
            maximize_budget();

        printf("\nDo you want to continue this program?(yes/no) :");
        scanf("%s",rotate);
        getchar();
    }
    printf("\n********** THANK YOU! **********\n\n");
    return 0;
}

void price_demand(){
    float f_price,c_price,f_demand,c_demand,PED,R1=0,R2=0,
          Total_revenue=0;
    char idea;

    printf("Enter your price and changed price :");
    scanf("%f %f",&f_price,&c_price);
    printf("Enter your quantity demand and changed quantity demand :");
    scanf("%f %f",&f_demand,&c_demand);

    PED = ((c_demand-f_demand) / (c_price-f_price))*(f_price/f_demand);
    if(PED<0){
        PED=PED-(PED*2);
    }


    printf("\nPrice Elasticity Of Demand = %.2f\n",PED);
    if(PED>1){
        printf("---This is an Elastic.---\n");
        if(c_price>f_price)
            printf("---Total revenue is Decrease---\n");
        else
            printf("---Total revenue is Increase---\n");
    }
    if(PED<1 && PED >0){
        printf("---This is an Inelastic.---\n");
        if(c_price>f_price)
            printf("---Total revenue is Increase---\n");
        else
            printf("---Total revenue is Decrease---\n");
    }

    printf("\nYou want to know idea about revenue values?(y/n) :");
    getchar();
    scanf("%c",&idea);
    getchar();

    if(idea =='y'){
        R1= f_price*f_demand;
        R2= c_price*c_demand;
        Total_revenue=R2-R1;

        printf("First revenue    = %.2f\n",R1);
        printf("Second revenue   = %.2f\n",R2);
        printf("Increase revenue = %.2f\n",Total_revenue);
    }

}

void price_supply(){
    float f_price,c_price,f_supply,c_supply,PES;

    printf("Enter your price and changed price :");
    scanf("%f %f",&f_price,&c_price);
    printf("Enter your quantity supply and changed quantity supply :");
    scanf("%f %f",&f_supply,&c_supply);

    PES = ((c_supply-f_supply) / (c_price-f_price))*(f_price/f_supply);
    if(PES<0){
        PES=PES-(PES*2);
    }


    printf("\nPrice Elasticity Of Supply = %.2f\n",PES);
    if(PES>1){
        printf("---This is an Elastic.---\n");
        printf("---Supply change value is large.---\n");
    }
    if(PES<1){
        printf("---This is an Inelastic.---\n");
        printf("---Supply change value is small.---\n");
    }
}

void income_demand(){
    float f_demand,c_demand,f_income,c_income,YED,Q,I;

    printf("\nEnter your income and changed income :");
    scanf("%f %f",&f_income,&c_income);
    printf("Enter your quantity demand and changed quantity demand :");
    scanf("%f %f",&f_demand,&c_demand);

    Q=(c_demand-f_demand)/f_demand;
    I=(c_income-f_income)/f_income;
    YED=Q/I;

    printf("\nIncome elasticity of demand = %.2f\n",YED);
    if(YED>0)
        printf("---This good is Normal good---\n");
    else
        printf("---This good is Inferior good---\n");
}

void cross_demand(){
     float x1_demand,x2_demand,y1_price,y2_price,XED,Q,P;
    printf("Enter your food X quantity demand and changed quantity demand :");
    scanf("%f %f",&x1_demand,&x2_demand);
    printf("\nEnter your food Y price and changed price :");
    scanf("%f %f",&y1_price,&y2_price);

     Q=(x2_demand-x1_demand)/x1_demand;
     P=(y2_price-y1_price)/y1_price;
     XED=Q/P;

    printf("\nCross elasticity of demand = %.2f\n",XED);
    if(XED>0)
        printf("---X and Y good are substitute goods---\n");
    else if(XED<0)
        printf("---X and Y good are complementary goods---\n");
    else
        printf("---No relationship between X and Y goods---\n");

}


void maximize_budget(){
     int unit;
     char option;
     float yu,xu,budget,price_x,price_y;

    printf("\nEnter available budget :");
    scanf("%f",&budget);
    printf("Enter Price of good X and Y :");
    scanf("%f %f",&price_x,&price_y);
    printf("Enter Unit consumed :");
    scanf("%d",&unit);
    printf("\n---You know total utility or marginal utility (t/m):");
    getchar();
    scanf("%c",&option);
    getchar();

    float x[unit],y[unit],xx[unit],yy[unit];
    if(option=='m'){
        printf("**Enter marginal utility**\n");
        for (int i = 0; i <unit ; ++i) {
            printf("    %d :",i+1);
            scanf("%f %f",&x[i],&y[i]);

        }
        for(int i = 0; i <unit ; ++i){
            xu=x[i]/price_x;
            for (int j = 0; j <unit ; ++j) {

                yu=y[j]/price_y;
                if(xu==yu){
                    if(((i+1.0)*price_x) + ((j+1.0)*price_y) == budget){
                        printf("\nConsumption bundle is X= %d  Y= %d\n",i+1,j+1);
                        goto jump1;
                    }
                }
            }
        }
        jump1:;
    }
    else if(option=='t') {
        printf("**Enter Total utility**\n");
        for (int i = 0; i < unit; ++i) {
            printf("    %d :", i + 1);
            scanf("%f %f", &x[i], &y[i]);
        }
        for (int k = 1; k < unit; ++k) {
            xx[k] = x[k] - x[k - 1];
            yy[k] = y[k] - y[k - 1];
        }
        for (int i = 0; i < unit; ++i) {
            xu = xx[i] / price_x;
            for (int j = 0; j < unit; ++j) {

                yu = yy[j] / price_y;
                if (xu == yu) {
                    if (((i + 1.0) * price_x) + ((j + 1.0) * price_y) == budget) {
                        printf("\nConsumption bundle is X= %d  Y= %d\n", i + 1, j + 1);
                        goto jump2;
                    }
                }
            }
        }
        jump2:;

    } else
        printf("\n---Input is incorrect---\n");
}