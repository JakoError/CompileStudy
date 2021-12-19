%{

#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);

%}

%union{
	int iValue;
	String sValue;
	Bean bean;
};
%token <iValue> INTCONST
%token <sValue> IDENT
%token BREAK CONST CONTINUE DO ELSE FOR IF INT MAIN RETURN VOID WHILE AND OR EQU_CMP NEQU_CMP LESE_CMP GREE_CMP
%type  <bean>   Root CompUnit Decl ConstDecl ConstDefs ConstDef ConstInitVals ConstInitVal VarDecl VarDefs VarDef
                InitVals InitVal FuncDef FuncFParams FuncFParam Block BlockItems BlockItem Stmt Exps
                Exp Cond LVal PrimaryExp Number UnaryExp FuncRParams MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExps
                ConstExp
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
Root: Root CompUnit  {addBean(root,$2);}
	| CompUnit       {addBean(root,$1);}

CompUnit: Decl      {$$ = beanInfo("CompUnit","Decl");addBean($$,$1);}
		| FuncDef   {$$ = beanInfo("CompUnit","FuncDef");addBean($$,$1);}
		;

Decl: ConstDecl     {$$ = $1;}
	| VarDecl       {$$ = $1;}
	;

ConstDecl: CONST INT ConstDefs ';'    {$$ = beanInfo("ConstDecl","int");addBeans($$,$3);}
         ;

ConstDefs: ConstDef ',' ConstDefs   {$$ = beanInfo("ConstDefs",NULL);addBean($$,$1);addBeans($$,$3);}
         | ConstDef                 {$$ = beanInfo("ConstDefs",NULL);addBean($$,$1);}
         ;

ConstDef: IDENT ConstExps '=' ConstInitVal  {$$ = beanInfo("ConstDef",$1);addBean($$,$4);}
        ;

ConstInitVals: ConstInitVal ',' ConstInitVals   {$$ = beanInfo("ConstInitVals",NULL);addBean($$,$1);addBeans($$,$3);}
             | ConstInitVal                     {$$ = beanInfo("ConstInitVals",NULL);addBean($$,$1);}
             ;

ConstInitVal: ConstExp              {$$ = beanInfo("ConstInitVal",NULL);addBean($$,$1);}
            | '{' '}'               {$$ = beanInfo("ConstInitVal",NULL);}
            | '{' ConstInitVals '}' {$$ = $2;}
            ;

VarDecl: INT VarDefs ';' {$$ = beanInfo("VarDecl","int");addBean($$,$2);}
       ;

VarDefs: VarDef ',' VarDefs   {$$ = beanInfo("VarDefs",NULL);addBean($$,$1);addBeans($$,$3);}
       | VarDef               {$$ = beanInfo("VarDefs",NULL);addBean($$,$1);}
       ;

VarDef: IDENT ConstExps '=' InitVal     {$$ = beanInfo("VarDef",$1);addBean($$,$2);addBean($$,$4);}
      | IDENT ConstExps                 {$$ = beanInfo("VarDef",$1);addBean($$,$2);}
      ;

InitVals: InitVal ',' InitVals  {$$ = beanInfo("InitVals",NULL);addBean($$,$1);addBeans($$,$3);}
        | InitVal               {$$ = beanInfo("InitVals",NULL);addBean($$,$1);}
        ;

InitVal: Exp                {$$ = beanInfo("InitVal",NULL);addBean($$,$1);}
       | '{' '}'            {$$ = beanInfo("InitVal","{}");}
       | '{' InitVals '}'   {$$ = beanInfo("InitVal","{}");addBean($$,$2);}
       ;

FuncDef: INT IDENT '(' ')' Block               {$$ = beanInfo("FuncDef-int",$2);addBean($$,$5);}
       | VOID IDENT '(' ')' Block              {$$ = beanInfo("FuncDef-void",$2);addBean($$,$5);}
       | INT IDENT '(' FuncFParams ')' Block   {$$ = beanInfo("FuncDef-int",$2);addBean($$,$4);addBean($$,$6);}
       | VOID IDENT '(' FuncFParams ')' Block  {$$ = beanInfo("FuncDef-void",$2);addBean($$,$4);addBean($$,$6);}
       | INT MAIN '(' ')' Block                {$$ = beanInfo("FuncDef-int","main");addBean($$,$5);}
       ;

FuncFParams: FuncFParam ',' FuncFParams     {$$ = beanInfo("FuncFParams",NULL);addBean($$,$1);addBeans($$,$3);}
           | FuncFParam                     {$$ = beanInfo("FuncFParams",NULL);addBean($$,$1);}
           ;

FuncFParam: INT IDENT                 {$$ = beanInfo("FuncFParam-int",$2);}
          | INT IDENT '[' ']' Exps    {$$ = beanInfo("FuncFParam-int[]",$2);addBean($$,$5);}
          ;

Block: '{' BlockItems '}'  {$$ = beanInfo("Block",NULL);addBean($$,$2);}
     ;

BlockItems: BlockItem BlockItems    {$$ = beanInfo("BlockItems",NULL);addBean($$,$1);addBeans($$,$2);}
          |                         {$$ = beanInfo("BlockItems","empty  ");}
          ;

BlockItem: Decl     {$$ = beanInfo("BlockItem","Decl");addBean($$,$1);}
         | Stmt     {$$ = beanInfo("BlockItem","Stmt");addBean($$,$1);}
         ;

Stmt:';'                                {$$ = NULL;}
    | LVal '=' Exp ';'                  {$$ = beanInfo("Stmt","assign");addBean($$,$1);addBean($$,$3);}
    | Exp ';'                           {$$ = beanInfo("Stmt","Exp");addBean($$,$1);}
    | Block                             {$$ = beanInfo("Stmt","block");addBean($$,$1);}
    | IF '(' Cond ')' Stmt ELSE Stmt    {$$ = beanInfo("Stmt","if-else");addBean($$,$3);addBean($$,$5);addBean($$,$7);}
    | IF '(' Cond ')' Stmt   %prec LOWER_THAN_ELSE    {$$ = beanInfo("Stmt","if");addBean($$,$3);addBean($$,$5);}
    | WHILE '(' Cond ')' Stmt           {$$ = beanInfo("Stmt","while");addBean($$,$3);addBean($$,$5);}
    | BREAK ';'                         {$$ = beanInfo("Stmt","break");}
    | CONTINUE ';'                      {$$ = beanInfo("Stmt","continue");}
    | RETURN ';'                        {$$ = beanInfo("Stmt","return");}
    | RETURN Exp ';'                    {$$ = beanInfo("Stmt","return");addBean($$,$2);}
    ;

Exps: '[' Exp ']' Exps  {$$ = beanInfo("Exps",NULL);addBean($$,$2);addBeans($$,$4);}
    |                   {$$ = beanInfo("Exps",NULL);}
    ;

Exp: AddExp  {$$ = $1;}
   ;

Cond: LOrExp    {$$ = beanInfo("Cond",NULL);addBean($$,$1);}
    ;

LVal: IDENT Exps    {$$ = beanInfo("LVal",$1);addBean($$,$2);}
    ;

PrimaryExp: '(' Exp ')' {$$ = $2;}
          | LVal        {$$ = $1;}
          | Number      {$$ = $1;}
          ;

Number: INTCONST    {$$ = beanInfo("Number",itos($1));$$->iValue = $1;}
      ;

UnaryExp: IDENT '(' ')'             {$$ = beanInfo("UnaryExp-function",$1);}
        | IDENT '(' FuncRParams ')' {$$ = beanInfo("UnaryExp-function",$1);addBean($$,$3);}
        | PrimaryExp                {$$ = $1;}
        | '+' UnaryExp              {$$ = beanInfo("UnaryExp","+");addBean($$,$2);}
        | '-' UnaryExp              {$$ = beanInfo("UnaryExp","-");addBean($$,$2);}
        | '!' UnaryExp              {$$ = beanInfo("UnaryExp","!");addBean($$,$2);}
        ;

FuncRParams: Exp ',' FuncRParams    {$$ = beanInfo("FuncRParams",NULL);addBean($$,$1);addBeans($$,$3);}
           | Exp                    {$$ = beanInfo("FuncRParams",NULL);addBean($$,$1);}
           ;

MulExp: MulExp '*' UnaryExp {$$ = beanInfo("MulExp","*");addBean($$,$1);addBean($$,$3);}
      | MulExp '/' UnaryExp {$$ = beanInfo("MulExp","/");addBean($$,$1);addBean($$,$3);}
      | MulExp '%' UnaryExp {$$ = beanInfo("MulExp","%");addBean($$,$1);addBean($$,$3);}
      | UnaryExp            {$$ = $1;}
      ;

AddExp: AddExp '+' MulExp {$$ = beanInfo("AddExp","+");addBean($$,$1);addBean($$,$3);}
      | AddExp '-' MulExp {$$ = beanInfo("AddExp","-");addBean($$,$1);addBean($$,$3);}
      | MulExp            {$$ = $1;}
      ;

RelExp: RelExp '<' AddExp       {$$ = beanInfo("RelExp","<");addBean($$,$1);addBean($$,$3);}
      | RelExp '>' AddExp       {$$ = beanInfo("RelExp",">");addBean($$,$1);addBean($$,$3);}
      | RelExp LESE_CMP AddExp  {$$ = beanInfo("RelExp","<=");addBean($$,$1);addBean($$,$3);}
      | RelExp GREE_CMP AddExp  {$$ = beanInfo("RelExp",">= ");addBean($$,$1);addBean($$,$3);}
      | AddExp                  {$$ = $1;}
      ;

EqExp: EqExp EQU_CMP RelExp     {$$ = beanInfo("EqExp","==");addBean($$,$1);addBean($$,$3);}
     | EqExp NEQU_CMP RelExp    {$$ = beanInfo("EqExp","!=");addBean($$,$1);addBean($$,$3);}
     | RelExp                   {$$ = $1;}
     ;

LAndExp: EqExp AND LAndExp      {$$ = beanInfo("LAndExp","&&");addBean($$,$1);addBean($$,$3);}
       | EqExp                  {$$ = $1;}
       ;

LOrExp: LAndExp OR LOrExp      {$$ = beanInfo("LOrExp","||");addBean($$,$1);addBean($$,$3);}
      | LAndExp                {$$ = $1;}
      ;

ConstExps: '[' ConstExp ']' ConstExps   {$$ = beanInfo("ConstExps",NULL);addBean($$,$2);addBeans($$,$4);}
         |                              {$$ = NULL;}
         ;

ConstExp: AddExp {$$ = $1;}
        ;


%%
void yyerror(char *s){
    printf("%s\n", s);
    if(stderr!=NULL)
		fprintf(stderr, "%s\n", s);
}