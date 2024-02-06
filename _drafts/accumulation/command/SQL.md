#### 码的概念

1、候选码：**能够唯一标识一条记录的最小属性集。若关系中的一个属性或属性组的值能够唯一地标识一个元组，且他的真子集不能唯一的标识一个元组，则称这个属性或属性组做候选码。**

2、主码：主码指主关键字。主关键字(primary key)是表中的一个或多个字段，它的值用于唯一地标识表中的某一条记录。在两个表的关系中，主关键字用来在一个表中引用来自于另一个表中的特定记录。主关键字是一种唯一关键字，表定义的一部分。一个表的主键可以由多个关键字共同组成，并且主关键字的列不能包含空值。主关键字是可选的，并且可在 CREATE TABLE 或 ALTER TABLE 语句中定义。

3、全码：All-key关系模型的所有属性组组成该 关系模式的 候选码，称为全码。即所有属性当作一个码。若关系中只有一个候选码,且这个候选码中包含全部属性,则该候选码为全码。如，关系模式R（T，C，S），属性T表示教师，属性C表示课程，属性S表示学生。假如设一个教师可以讲授多门课程，某门课程可以有多个教师讲授，学生可以听不同教师讲授的不同课程，那么，要区分关系中的每一个元组，这个关系模式R的码（主键）应为全属性T、C和S，即All-key。

4、外码：外码是相对于内码而言的辞汇。在计算机科学及相关领域中，外码指的是“外在的‘经过学习之后，可直接了解的编码形式（例如：文字或语音符号）’”。外键（foreign key）：子数据表中出现的父数据表的主键，称为子数据表的外键。


5、主属性：包含在任一候选码中的属性称主属性。简单来说，主属性是候选码所有属性的并集      非主属性  不包含在候选码中的属性称为非主属性。 非主属性是相对于主属性来定义的。

6、主码和候选码的区别：主码唯一标识，候选码是可以作为主码的码，主码一定是候选码的子集，但候选码不一定是主码。


```sql
SELECT DISTINCT Sno
FROM SC；
//distinct 去除重复的

SELECT Sno,Grade
FROM SC
WHERE Cno='3'
ORDER BY Grade DESC;
//查询选修了3号课程的学生的学号及其成绩，查询结果按分数的降序排列'DESC'降序排序'ASC'升序排序
descend	ascend

SELECT dNo,cNo,count(sc.sNo)
FROM sc JOIN student ON sc.sNO=student.sNo
GROUP BY dNo,cNo 
HAVING COUNT(sc.cNo)>4;
//HAVING 是对分组之后的元组进行筛选
//where是在分组之前对元组进行选哪个筛选

SELECT Sno,AVG(Grade)
FROM SC
GROUP BY Sno
HAVING AVG(Grade)>=90;
//查询平均成绩大于等于90分的学生学号和平均成绩。

CREATE VIEW [viewName] 
AS 
select


SELECT Cno,Credit
FROM Course
WHERE Cname LIKE 'DB\_Design'  ESCAPE '\';
ESCAPE'\'表示'\'是换码字符。这样匹配串中紧跟在'\'后面的字符'_'不再具有通配符的含义

drop table [tableName]
//删除表

delete from [tableName]
//删除表中的数据

insert into [tableName] values(),(),();
//向表中插入数据
```

