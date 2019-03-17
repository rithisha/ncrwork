/*qn 7(who have a manager)*/
select ename,empno from emp where manager is not null
/*qn 8* total renumeration*/
select ename,sal+isnull(comm,0)"total renumeration" from emp;
/*qn 9 */
select ename,sal*12"total salary",isnull(comm,0)*12"total commision" from emp where sal>isnull(comm,0) AND deptno in(select deptno from dept where dname='SALES') order by sal desc,ename;
/*qn 10*/
select concat(concat(ename,' is a '),job),ROUND(1.15*sal,0) from emp 
/*qn 11*/
select ename,REPLACE(job,'SALESMAN','SALESPERSON')"job" from emp where job='SALESMAN';
/*qn 12*/
select job,MAX(sal)"maximum salary",MIN(sal)"minimum salary" from emp group by job; 
/*qn 13*/
select COUNT(job) from emp where job='MANAGER';
/*qn 14*/
select job,AVG(sal)"average salary",sum(sal+isnull(comm,0))"total renumeration" from emp group by job;
/*qn 15*/
select max(sal)-min(sal) from emp;
/*qn 16*/
select dname,deptno from dept where deptno in(select deptno from emp group by deptno having count(empno)>3);
/*qn 17*/
select CASE when count(empno)=count(*) then 'true' else 'false' end from emp;
/*qn 18*/
select ename,sal,manager from emp where sal in(select min(sal) from emp group by manager);  
/*to find details of each employee under a single manger*/
select manager,ename,empno from emp where manager in(select manager from emp group by manager) order by manager;
/*qn 19(equi join)*/
select ename,dname from emp e,dept d where e.deptno=d.deptno order by dname;
/*qn 20*/
select ename,d.deptno,dname from emp e,dept d where e.deptno=d.deptno;
/*qn 21 (we can access sal of emp table by joining */
select ename,loc,d.deptno,dname from emp e,dept d where e.deptno=d.deptno and sal>1500;
/*qn 22*/
select ename,empno,grade from emp,salgrade where grade=3 and (sal between losal and hisal);
/*qn 23(can also do this using sub queries*/
select ename,empno,loc from emp e,dept d where loc='DALLAS' and e.deptno=d.deptno;
/*qn 24*/
select ename,job,sal,grade,dname from emp e,salgrade,dept d where (e.deptno=d.deptno) and grade in(select grade from salgrade where sal between losal and hisal) and job<>'CLERKS' order by sal desc;
/*qn 25*/
select * from emp where sal*12=36000 or job='CLERKS';
/*qn 26*/
select dname from dept where deptno not in(select deptno from emp);
/*qn 27*/
select ename,empno,job,sal from emp where sal in(select max(sal) from emp group by job) order by sal desc;
/*qn 28*/
select ename,empno,job from emp where hiredate in(select max(hiredate) from emp group by deptno);
/*qn 29*/
select count(*)"count",sum(sal)"sum of salaries",avg(sal)"average salary" from emp group by deptno;


