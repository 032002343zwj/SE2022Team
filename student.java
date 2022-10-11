package word;

import java.util.Iterator;

public class student {
    private String name;
    private String sex;
    private String num;
    private double grate;

    private double chance;   //出勤率

    private boolean flag=false;



    public  student(){

    }


    public student(String name,String sex,String num,double grate){
        this.name=name;
        this.sex=sex;
        this.num=num;
        this.grate=grate;
    }

    public String getSex(){
        return sex;
    }
    public void setSex(String sex){
        this.sex=sex;
    }

    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name=name;
    }

    public String getNum(){
        return num;
    }
    public void setNum(String num){
        this.num=num;
    }

    public  double getChance(){
        return chance;
    }
    public  void setChance(double chance){
        this.chance=chance;
    }

    public boolean getFlag(){
        return flag;
    }
    public void setFlag(boolean flag){
        this.flag=flag;
    }

    public double getGrate(){
        return grate;
    }
    public void setGrate(double grate){
        this.grate=grate;
    }



}
