
select ename,sal*12 "annual 
sal",isnull(comm,0) from emp where sal>isnull(comm,0) and job='SALESMAN' order by sal,ename;
select * from emp where deptno in(select deptno from dept where loc='DALLAS');
select * from dept where deptno not in(select deptno from emp group by deptno);/*we select unique dept nos in emp table and check whch are no in dept */
select ename from emp where deptno in(select deptno from dept where dname='SALES');
select ename from emp where deptno in(select deptno from emp where ename='SMITH');
select ename,sal,deptno from emp X where sal=(select max(sal) from emp where deptno=x.deptno group by deptno);/*emp with max sal n their dept//can also use orderby*/