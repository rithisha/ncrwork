use mysqldb;
create table dept(
deptno int not null,
deptname varchar(20) not null,
location varchar(20) not null,
constraint dept_deptno_pk primary key(deptno)
);
create table emp(
empno int not null,
ename varchar(20) not null,
sal int not null,
deptno int not null,
job varchar(20) not null,
hiredate date,
grade int,
commission int,
constraint emp_empno_pk primary key(empno),
constraint emp_deptno_fk foreign key(deptno) references dept(deptno)
);
insert into dept values(10,'R&D','hyderbad'),(20,'testing','chennai'),(30,'development','banglore')
insert into emp values(1,'rithisha',2000,20,'tester','2019-07-08',9,500),(2,'sandy',2000,30,'developer','2019-07-09',9,500),(3,'manu',3000,10,'manager','2019-04-15',8,400)
select * from dept
select ename,sal from emp where sal<2000 AND sal>1000;/*qn 1*/
update emp set sal=1500 where empno=3;
insert into dept values(40,'health','hyderabad'),(50,'finance','chennai');
/*qn 2*/
select deptno,deptname from dept order by deptname;
/*qn 3*/
select job from emp order by job;
/*qn 4*/
select ename,empno,sal,job,hiredate,deptno from emp where deptno=10 OR deptno=20 order by ename;
/*qn 6*/
insert into emp values(4,'SMITH',1700,40,'health manager','2019-07-08',9,500);
select ename from emp where ename like '%ll%' OR ename like '%TH%';

