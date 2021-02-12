package C0compiler;

public class C0test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		System.out.println(line);
////		System.out.println(len);
//		do {
//			getsym();
//		}
//		while(cc<len);	
//		cc=0;
//		gen(fct.ADD,10,9);
//		outInstruct();
//		Ptx ptx=new Ptx();
//		id="a";
//		enter(object.integer,ptx,1,new Pdx());
//		id="b";
//		enter(object.void_function,ptx,10,new Pdx());
//		id="c";
//		enter(object.int_function,ptx,1,new Pdx());
//		outTable();
//		System.out.println("position:"+position("aa",table_num-1));;
//
//		gen(fct.CAL,1,1);
//		outInstruct();
		
		
		
		
		
		
//		while(sym==symbol.voidsym||sym==symbol.intsym)	//C0总是以void或int开头
//		{
//			if(sym==symbol.intsym)	//如果是int，则可能是全局变量或函数
//			{
//				getsym();
//				if(sym==symbol.ident)		//int后是标识符
//				{
//					getsym();
//					if(sym==symbol.comma||sym==symbol.semicolon)	//定义数据
//					{
//						dx.value+=4;	//初始化三个单元,在该层的相对位置，为1个return语句的隐藏单元和三个最初始化的默认单元，分别占据了栈的0、1、2、3四个单元位置，变量声明从第五个单元位置开始，下标为4
//						gen(fct.INT,0,5);	//生成一个单位时的栈空间，1+3+1
//						enter(object.integer,tx,lev,dx);	//插入符号表当中
//						do {
//							while(sym==symbol.comma) {		//如果是','则后应跟多个变量声明
//								getsym();
//								if(sym==symbol.ident)		//后跟多个变量声明
//								{
//									code[cx0].a++;			//此时的栈INT指令每生成一个变量便+1
//									enter(object.integer,tx,lev,dx);	//每有一个变量便加入到符号表中
//									getsym();
//								}
//								else error(4);
//							}
//							if(sym==symbol.semicolon)		//如果后跟';'则表示声明变量结束，跳出变量声明循环
//							{
//								getsym();
//								break;
//							}
//							else error(5);
//						}while(sym==symbol.ident);
//						
//						code[2]=code[0];
//						code[0]=code[1];
//						code[1]=code[2];
//						cx++;
//						
//					}
//					else if(sym==symbol.lparen)//int后是函数
//					{
//						if(lev==0)lev+=1;	//main函数为第一层，其他函数均为第二层，
//						dx.value=3;
//						lev++;
////						System.out.println(cx+" "+cx0);
//						cx0=cx;	//栈，保留此时cx，函数入口		//***这非常重要，用以函数返回时的回填table表字段的adr！！！***
//						funl=0;//该层函数的局部变量个数					
//						enter(object.int_function,tx,lev,dx);
//						getsym();
//						
//						gen(fct.JMP,0,cx);
//						gen(fct.CAL,0,cx);
//						if(sym!=symbol.rparen)error(6);	//缺少右小括号
//						else getsym();
//						if(sym!=symbol.lbrace)error(7);	//缺少左大括号
//						else
//						{
//							getsym();
//							statement(tx,lev,dx);
//						}
//						
//						
//						
//					}
//				}
//			}
//		}
	}
}