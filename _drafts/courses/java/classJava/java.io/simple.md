```java
package cn.edu.nwpu.soft;

import com.alibaba.fastjson2.JSON;
import com.alibaba.fastjson2.JSONArray;
import com.alibaba.fastjson2.JSONObject;
//import jdk.nashorn.internal.parser.JSONParser;
import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.*;

public class Student {

    private static BufferedReader stdIn =
            new  BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter stdOut =
            new  PrintWriter(System.out, true);
    private static PrintWriter  stdErr =
            new  PrintWriter(System.err, true);
    
    private ArrayList<UndergraduateStudent> undergraduateStudents = new ArrayList<UndergraduateStudent>();
    private ArrayList<GraduateStudent> graduateStudents = new ArrayList<GraduateStudent>();
    private ArrayList<DoctoralStudent> doctoralStudents = new ArrayList<DoctoralStudent>();


    public static void main(String[] args) throws IOException, ParseException{
        Student student = new Student();
        stdOut.println("Please enter characters to implement the function\n"+
                "[A]打印全部学生信息\n" +
                "[B]新增一个本科生\n" +
                "[C]新增一个研究生\n" +
                "[D]新增一个博士生\n" +
                "[E]按学号查找学生\n" +
                "[F]按姓名查找学生\n" +
                "[G]学生排序");
        student.readUS();
        student.readGS();
        student.readDS();
        student.run();
    }
    
    public void displayInfo() throws IOException {
        BufferedReader br1 = new BufferedReader(new FileReader("us.txt"));
        BufferedReader br2 = new BufferedReader(new FileReader("gs.json"));
        BufferedReader br3 = new BufferedReader(new FileReader("ds.xml"));
        String str1;
        while((str1 = br1.readLine()) != null){
            stdOut.println(str1);
        }
        String str2;
        while((str2 = br2.readLine())!= null){
            stdOut.println(str2);
        }
        String str3;
        while((str3 = br3.readLine())!= null){
            stdOut.println(str3);
        }
    }
    
    private void run() throws IOException{
        String str = stdIn.readLine();
        while(str != null)
        {
            if("A".equals(str))
            {
                displayInfo();
            }else if("B".equals(str))
            {
                stdOut.println("请输入学生信息，中间用_分隔");
                addUndergraduateStudent();
            }else if("C".equals(str))
            {
                stdOut.println("请输入学生信息，中间用_分隔");
                addGraduateStudent();
            } else if ("D".equals(str)) {
                stdOut.println("请输入学生信息，中间用_分隔");
                addDoctoralStudent();
            } else if ("E".equals(str)) {
                String number = stdIn.readLine();
                findStudentByNumber(number);
            }else if("F".equals(str))
            {
                String name = stdIn.readLine();
                findStudentByName(name);
            } else if ("G".equals(str)) {
                sort();
            }else {
                stdOut.println("输入不合法，请重新输入");
            }
            str = stdIn.readLine();
        }
    
    }
    
    public void readUS(){
        try{
            FileReader readFile = new FileReader("us.txt");
            BufferedReader br = new BufferedReader(readFile);
            String str = br.readLine();
            while(str != null) {
                StringTokenizer tokenizer = new StringTokenizer(str,"_");
                String studentNumber = tokenizer.nextToken();
                String studentName = tokenizer.nextToken();
                String g = tokenizer.nextToken();
                char gander;
                if("男".equals(g))
                {
                    gander='男';
                }else{
    
                    gander='女';
                }
                SimpleDateFormat formatter = new SimpleDateFormat("yyyy年MM月dd日");
                Date birthday = formatter.parse(tokenizer.nextToken());
                String academy = tokenizer.nextToken();
                String major = tokenizer.nextToken();
                String tutor = tokenizer.nextToken();
                undergraduateStudents.add(new UndergraduateStudent(studentNumber, studentName, gander, birthday, academy, major,tutor));
                str=br.readLine();
            }
        }catch (IOException | ParseException e){
            stdOut.println("US Read exception!");
        }
    }


    public void addUndergraduateStudent(){
        while(true) {
            try{
                String s= stdIn.readLine();
                StringTokenizer tokenizer=new StringTokenizer(s,"_");
                if(tokenizer.countTokens()!=7)
                {
                    stdOut.println("The input information parameter is incorrect, please re-enter it");
                    continue;
                }
                String studentNumber=tokenizer.nextToken();
                String studentName=tokenizer.nextToken();
                String g=tokenizer.nextToken();
                char gander;
                if("男".equals(g))
                {
    
                    gander='男';
                }else{
    
                    gander='女';
                }
                SimpleDateFormat formatter=new SimpleDateFormat("yyyy年MM月dd日");
                Date birthday=formatter.parse(tokenizer.nextToken());
                String academy=tokenizer.nextToken();
                String major=tokenizer.nextToken();
                String tutor=tokenizer.nextToken();
                UndergraduateStudent undergraduateStudent=new UndergraduateStudent(studentNumber, studentName, gander, birthday, academy, major,tutor);
                FileWriter fileWriter=new FileWriter("us.txt",true);
                fileWriter.write("\n"+s);
                fileWriter.flush();
                undergraduateStudents.add(undergraduateStudent);
                stdOut.println("Added successfully");
                break;
            }catch (ParseException | IOException e) {
                e.printStackTrace();
                stdOut.println("The input format is incorrect, please re-enter");
            }
    
        }
    }
    
    public void readGS() throws IOException, ParseException {
        try{
            FileReader readFile = new FileReader("gs.json");
            BufferedReader br = new BufferedReader(readFile);
            String str = br.readLine();
            StringBuilder sb = new StringBuilder(new String());
            while(str!=null){
                sb.append(str);
                str=br.readLine();
            }
            JSONArray array=JSONArray.parseArray(sb.toString());
            for(int i=0;i<array.size();i++) {
                JSONObject jsonObject = array.getJSONObject(1);
                String studentNumber = jsonObject.getString("studentNumber");
                String studentName = jsonObject.getString("studentName");
                String g = jsonObject.getString("gander");
                char gander;
                if("男".equals(g)) {
                    gander='男';
                }else{
                    gander='女';
                }
                SimpleDateFormat formatter = new SimpleDateFormat("yyyy年MM月dd日");
                Date birthday = formatter.parse(jsonObject.getString("birthday"));
                String academy = jsonObject.getString("academy");
                String major = jsonObject.getString("major");
                String supervisor = jsonObject.getString("supervisor");
                graduateStudents.add(new GraduateStudent(studentNumber,studentName,gander,birthday,academy,major,supervisor));
            }
        }catch (IOException | ParseException e){
            stdOut.println("GS Read exception");
        }
    }
    
    public void addGraduateStudent(){
        while(true){
            try{
                String s = stdIn.readLine();
                StringTokenizer tokenizer = new StringTokenizer(s,"_");
                if(tokenizer.countTokens() != 7) {
                    stdOut.println("The input information parameter is incorrect, please re-enter it");
                    continue;
                }
                String studentNumber = tokenizer.nextToken();
                String studentName = tokenizer.nextToken();
                String g = tokenizer.nextToken();
                char gander;
                if("男".equals(g)) {
                    gander='男';
                }else{
                    gander='女';
                }
                SimpleDateFormat formatter = new SimpleDateFormat("yyyy年MM月dd日");
                Date birthday = formatter.parse(tokenizer.nextToken());
                String academy = tokenizer.nextToken();
                String major = tokenizer.nextToken();
                String supervisor = tokenizer.nextToken();
                GraduateStudent graduateStudent = new GraduateStudent(studentNumber, studentName, gander, birthday,
                        academy, major,supervisor);
                graduateStudents.add(graduateStudent);
                FileWriter fileWriter = new FileWriter("gs.json",false);
                fileWriter.write(JSONArray.toJSONString(graduateStudents));
                fileWriter.flush();
                stdOut.println("Added successfully");
                break;
            }catch (ParseException | IOException e) {
                e.printStackTrace();
                stdOut.println("The input format is incorrect, please re-enter");
            }
    
        }
    }
    
    public void readDS() throws IOException {
        try{
            SAXReader reader =  new SAXReader();
            org.dom4j.Document doc = reader.read(new File("ds.xml"));
            Element root = doc.getRootElement();
            List<Element> list = root.elements();
            List<DoctoralStudent> dsList = new ArrayList<DoctoralStudent>();
            for(Element ds:list) {
                Element numberEle = ds.element("studentNumber");
                String studentNumber = numberEle.getText();
                Element nameEle = ds.element("studentName");
                String studentName = nameEle.getText();
                Element ganderEle = ds.element("gander");
                String g = ganderEle.getText();
                char gander;
                if("男".equals(g)) {
                    gander='男';
                }else{
                    gander='女';
                }
                Element dateEle = ds.element("birthday");
                String date = dateEle.getText();
                SimpleDateFormat formatter = new SimpleDateFormat("yyyy年MM月dd日");
                Date birthday = formatter.parse(date);
                Element academyEle = ds.element("academy");
                String academy = academyEle.getText();
                Element majorEle = ds.element("major");
                String major = majorEle.getText();
                Element supervisorEle = ds.element("supervisor");
                String supervisor = supervisorEle.getText();
                Element researchFieldsEle = ds.element("researchFields");
                String researchFields = researchFieldsEle.getText();
                doctoralStudents.add(new DoctoralStudent(studentNumber,studentName,gander,birthday,academy,major,supervisor,researchFields));
            }
        }catch (DocumentException | ParseException e){
            stdOut.println("DS Read exception");
        }
    
    }
    
    public void addDoctoralStudent(){
        while(true){
            try{
                String s= stdIn.readLine();
                StringTokenizer tokenizer=new StringTokenizer(s,"_");
                if(tokenizer.countTokens()!=8)
                {
                    stdOut.println("The input information parameter is incorrect, please re-enter it");
                    continue;
                }
                String studentNumber=tokenizer.nextToken();
                String studentName=tokenizer.nextToken();
                String g=tokenizer.nextToken();
                char gander;
                if("男".equals(g))
                {
                    gander='男';
                }else{
                    gander='女';
                }
                SimpleDateFormat formatter=new SimpleDateFormat("yyyy年MM月dd日");
                Date birthday=formatter.parse(tokenizer.nextToken());
                String academy=tokenizer.nextToken();
                String major=tokenizer.nextToken();
                String supervisor=tokenizer.nextToken();
                String researchFields=tokenizer.nextToken();
                DoctoralStudent doctoralStudent=new DoctoralStudent(studentNumber, studentName, gander, birthday, academy, major,supervisor,researchFields);
                doctoralStudents.add(doctoralStudent);
                stdOut.println("Added successfully");
                Document document = DocumentHelper.createDocument();
                Element root = document.addElement("doctoralStudents");
                for(DoctoralStudent ds : doctoralStudents){
                    Element root1 = root.addElement("studentInfo");
                    root1.addElement("studentNumber").addText(ds.getStudentNumber());
                    root1.addElement("studentName").addText(ds.getStudentName());
                    String string = Character.toString(ds.getGander());
                    root1.addElement("gander").addText(string);
                    SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy年MM月dd日");
                    String transformDate = simpleDateFormat.format(ds.getBirthday());
                    root1.addElement("birthday").addText(transformDate);
                    root1.addElement("academy").addText(ds.getAcademy());
                    root1.addElement("major").addText(ds.getMajor());
                    root1.addElement("supervisor").addText(ds.getSupervisor());
                    root1.addElement("researchFields").addText(ds.getResearchFields());
                }
                FileWriter out = new FileWriter("ds.xml",false);
                document.write(out);
                out.close();
                break;
            }catch (ParseException | IOException nfe) {
                nfe.printStackTrace();
                stdOut.println("The input format is incorrect, please re-enter");
            }
        }
    }
    
    public void findStudentByNumber(String number) {
        for(UndergraduateStudent undergraduateStudent:undergraduateStudents)
        {
            if(number.equals(undergraduateStudent.getStudentNumber()))
            {
                stdOut.println(undergraduateStudent.toString());
                break;
            }
        }
        for(GraduateStudent graduateStudent:graduateStudents)
        {
            if(number.equals(graduateStudent.getStudentNumber()))
            {
                stdOut.println(graduateStudent.toString());
                break;
            }
        }
        for(DoctoralStudent doctoralStudent:doctoralStudents)
        {
            if(number.equals(doctoralStudent.getStudentNumber()))
            {
                stdOut.println(doctoralStudent.toString());
                break;
            }
        }
    }
    
    public void findStudentByName(String name) {
        for(UndergraduateStudent undergraduateStudent:undergraduateStudents)
        {
            if(name.equals(undergraduateStudent.getStudentName()))
            {
                stdOut.println(undergraduateStudent.toString());
            }
        }
        for(GraduateStudent graduateStudent:graduateStudents)
        {
            if(name.equals(graduateStudent.getStudentName()))
            {
                stdOut.println(graduateStudent.toString());
            }
        }
        for(DoctoralStudent doctoralStudent:doctoralStudents)
        {
            if(name.equals(doctoralStudent.getStudentName()))
            {
                stdOut.println(doctoralStudent.toString());
            }
        }
    }
    
    public void sort()
    {
        Collections.sort(undergraduateStudents);
        Collections.sort(graduateStudents);
        Collections.sort(doctoralStudents);
        for(UndergraduateStudent undergraduateStudent:undergraduateStudents) {
            stdOut.println(undergraduateStudent.toString());
        }
        stdOut.println(JSONArray.toJSONString(graduateStudents));
        for(DoctoralStudent doctoralStudent : doctoralStudents){
            stdOut.println(doctoralStudent.toString());
        }
    }
}
```