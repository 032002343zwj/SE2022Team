package word;

import word.SE2022Team.student;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.text.DecimalFormat;
import java.util.*;

public class test01 {

    public static void main(String[] args) throws IndexOutOfBoundsException, IOException {

        int i=5;
        while(i!=0){


            ArrayList<student> al=new ArrayList<student>();   //将一个学生的出勤信息放入数组
            PrintWriter pw=new PrintWriter(new FileWriter("D:\\IDEA\\module\\module\\src\\word\\class.csv"+i),true);

            Scanner sc=new Scanner(System.in);
            System.out.println("请输入"+i+"班的人数：");
            int total;
            total=sc.nextInt();
            Random r=new Random();
            while(total!=0){    //产生一个学生的出勤信息
                String name=getName();
                String sex=getSex();
                String num=getNum();
                double grate=getGrate();
                while(grate<1 || grate>4){
                    grate=getGrate();
                }
                DecimalFormat df=new DecimalFormat("0.0000");
                grate= Double.parseDouble(df.format(grate));
                student s=new student(name,sex,num,grate);
                if(grate>=3.6&&grate<4.0){  //根据绩点高低赋予每个人初始的出勤率
                    s.setChance(95.0);
                }
                else if(grate>=3.0&&grate<3.6){
                    s.setChance(90.0);
                }
                else if(grate>=2.5&&grate<3.0){
                    s.setChance(70.0);
                }
                else if(grate>=2.0&&grate<2.5){
                    s.setChance(60.0);
                }
                else if(grate<2.0){
                    s.setChance(50.0);
                }
                al.add(s);
                total--;

            }

            Random random=new Random();
            int choice=r.nextInt(4)+4;  //在5~8中随机产生这个课程缺勤80%的学生人数
            getChoice(al,choice);

            for (student s1: al){
                StringBuilder sb=new StringBuilder();
                sb.append(s1.getName()).append("\t\t").append(s1.getSex()).append("\t\t").append(s1.getNum()).append("\t\t").append(s1.getGrate()).append("\t\t").append(condition(s1)).append("\t\t");
                String ts=sb.toString();
                pw.println(ts);
            }


            pw.close();
            i--;

        }



    }

    public static String condition(student s1) {    //生产20次出勤信息(0为缺勤，1为出勤)
        StringBuilder stu=new StringBuilder();
        if(s1.getFlag()){   //为该课程80%缺课的同学
            int choice=16;
            for (int i=0;i<20;i++){
                Random random=new Random();
                int x=random.nextInt(200);
                if(x<160){
                    if(choice!=0){
                        stu.append(0).append("\t\t");
                        choice--;
                    }
                    else if(choice==0){
                        stu.append(1).append("\t\t");
                    }
                }
                else  {
                    stu.append(1).append("\t\t");
                }

            }
        }
        else{
            double sum=s1.getChance();  //出勤率
//            Random random=new Random();
//            int y=random.nextInt(100);
//            if(y>sum){
//                stu.append(0).append("\t\t");
//            }
//            else{
//
//            }
            for (int i=0;i<20;i++){
                Random random1=new Random();
                int x=random1.nextInt(100);
                if(x>sum){  //缺勤
                    stu.append(0).append("\t\t");
                    sum--;
                }
                else{     //出勤
                    stu.append(1).append("\t\t");
                }
            }

            s1.setChance(sum);
        }
        return  stu.toString();
    }

    public static void getChoice(ArrayList<student> al, int choice) {  //挑选缺课本课程80%的学生
        for (student stu: al){
            Random r=new Random();
            int x=r.nextInt(100);
            if(choice!=0){
                if(stu.getGrate()<=2.5){
                    stu.setFlag(true);
                    choice--;
                }
            }
        }
    }


    public static double getGrate() {   //正态分布获得绩点
        Random r=new Random();
        double f=r.nextGaussian()+3;
        return f;
    }

    public static String getSex() {
        Random r=new Random();
        int num=r.nextInt(2);
        if(num==0){
            return "男";
        }
        else {
            return "女";
        }
    }

    public static String getNum() {
        String s="032";
        Random r=new Random();
        int total=6;
        while(total!=0){
            int num=r.nextInt(9);
            s=s+num;
            total--;
        }
        return s;
    }

    public static String getName(){
        Random random = new Random();
        /* 598 百家姓 */
        String[] Surname = {"赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈", "蒋", "沈", "韩", "杨", "朱", "秦", "许","何","张", "孔", "曹", "严", "魏", "姜", "谢","苏", "潘", "范" ,"鲁", "韦", "昌", "马",  "方", "岑", "雷", "贺","罗","钟"};


        String me[]={"伟","铭","月","炳","贝","欣","颖","凡","汉","杰","兰","隆","东","峰","歌","国","骏","坤","亮","茵","晓","桐","琳","德","岳","辰"};

        int index = random.nextInt(Surname.length - 1);
        String name = Surname[index]; //获得一个随机的姓氏

        Random r=new Random();
        int num=r.nextInt(100);
        /* 从常用字中选取一个或两个字作为名 */
        if (num<70) {
            int Index=random.nextInt(me.length);
            name += me[Index]+ getChinese();
        } else {
            name += getChinese()+"  ";
        }
        return name;
    }

    public static String getChinese() {
        String str = null;
        int highPos, lowPos;
        Random random = new Random();
        Random r=new Random();
        highPos = (176 + Math.abs(random.nextInt(55)));//区码，0xA0打头，从第16区开始，即0xB0=11*16=176,16~55一级汉字，56~87二级汉字
        random = new Random();
        lowPos = 161 + Math.abs(random.nextInt(60));//位码，0xA0打头，范围第1~94列

        byte[] bArr = new byte[2];
        bArr[0] = (new Integer(highPos)).byteValue();
        bArr[1] = (new Integer(lowPos)).byteValue();
        try {
            str = new String(bArr, "GB2312");    //区位码组合成汉字
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return str;
    }
}