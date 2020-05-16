// -------------------------------------------------------------------
// renew.h
// -------------------------------------------------------------------
#define __DEBUGLINE__		547				// 0:debug�Ȃ�, 1>:line_no

#define _SOH				0x01			// TAB�}���ʒu
// #define _STX				0x02			// #define �Ŏg�p ����`�Ž�߰����܂߂���ۯ��̊J�n�w��
// #define _ETX				0x03			// TAB�̕ς��
#define _TAB				0x09
#define _CR					0x0d
#define _ESC				0x1b
#define _LF					0x0a
#define CRLF				"\r\n"

#define BIT0				1
#define BIT1				2
#define BIT2				4
#define BIT3				8
#define BIT4				0x10
#define BIT5				0x20
#define BIT6				0x40
#define BIT7				0x80
#define BIT8				0x100
#define BIT9				0x200
#define BIT10				0x400
#define BIT11				0x800
#define BIT12				0x1000
#define BIT13				0x2000
#define BIT14				0x4000
#define BIT15				0x8000

#define BIT16				0x10000
#define BIT17				0x20000
#define BIT18				0x40000
#define BIT19				0x80000
#define BIT20				0x100000
#define BIT21				0x200000
#define BIT22				0x400000
#define BIT23				0x800000
#define BIT24				0x1000000
#define BIT25				0x2000000
#define BIT26				0x4000000
#define BIT27				0x8000000
#define BIT28				0x10000000
#define BIT29				0x20000000
#define BIT30				0x40000000
#define BIT31				0x80000000

// ------------- ���s���̎��(ope_type) ------------------------------------

// -------- refresh(), reform_story() �p ----------------
#define T_MASK				0xfffffff0
#define T_MASK_MES			0x00000100		// "comment
// #define T_MES11			0x00000101		// "//" +TAB + message(program�|�󂠂�) �s����"//"�ǉ��K�v
// #define T_MES12			0x00000102		// TAB + "//" + message(program�|�󂠂�) �r����"//"�ǉ��K�v
// #define T_MES13			0x00000103		// "// " + message(program�|�󂠂�) �s����"//"�ǉ��K�v
#define T_MES14				0x00000104		// "//" + TAB + message �s����"//"�ǉ��K�v
#define T_MES15				0x00000105		// TAB + "//" + message �r����"//"�ǉ��K�v
#define T_MES16				0x00000106		// "//" + message �s����"//"�ǉ��K�v
#define T_MES17				0x00000107		// �����̂܂�

// --------------------------------------------
#define T_IF				0x00000200
#define T_IF1				0x00000201
#define T_IF2				0x00000202		// 2��� �㏈��
#define T_IF3				0x00000203		// 3���
#define T_IF4				0x00000204		// �I���҂�
#define T_IF5				0x00000205		// �����s�̏���, 1�sporgram����
#define T_IF6				0x00000206		// ���ʂׂ̈����܂ŕK�v
// #define T_IF9			0x00000209		// if(),���s��else���̌����p
#define T_IFX				0x0000020f		// if()�̑���

#define T_ELSE				0x00000400
#define T_ELSE1				0x00000401
#define T_ELSE2				0x00000402
#define T_ELSE3				0x00000403
#define T_ELSE4				0x00000404
#define T_ELSE5				0x00000405
#define T_ELSE6				0x00000406		// ���ʂׂ̈����܂ŕK�v
#define T_ELSE_IF			0x00000407		// 'else if('�̕�
#define T_ELSE_BIG			0x00000408		// 'else {'�̕�
// #define T_ELSE9			0x00000409		// ���s��else���̌����p
#define T_ELSEX				0x00000404		// else�̑���

#define T_SWITCH			0x00000800
#define T_SWITCH1			0x00000801
#define T_SWITCH2			0x00000802
#define T_SWITCH3			0x00000803
#define T_SWITCH4			0x00000804
#define T_SWITCH5			0x00000805
#define T_SWITCH6			0x00000806		// ���ʂׂ̈����܂ŕK�v
#define T_SWITCHX			0x0000080f

#define T_WHILE				0x00001000
#define T_WHILE1			0x00001001
#define T_WHILE2			0x00001002
#define T_WHILE3			0x00001003
#define T_WHILE4			0x00001004
#define T_WHILE5			0x00001005
#define T_WHILE6			0x00001006		// ���ʂׂ̈����܂ŕK�v
#define T_WHILEX			0x0000100f

#define T_DO				0x00002000
#define T_DO1				0x00002001
#define T_DO2				0x00002002
#define T_DO3				0x00002003
#define T_DO4				0x00002004
#define T_DO5				0x00002005
#define T_DO6				0x00002006		// ���ʂׂ̈����܂ŕK�v
#define T_DOX				0x0000200f

#define T_TRY				0x00004000
#define T_TRY1				0x00004001
#define T_TRY2				0x00004002
#define T_TRY3				0x00004003
#define T_TRY4				0x00004004
#define T_TRY5				0x00004005
#define T_TRY6				0x00004006		// ���ʂׂ̈����܂ŕK�v
#define T_TRYX				0x0000400f

#define T_FOR				0x00008000
#define T_FOR1				0x00008001
#define T_FOR2				0x00008002
#define T_FOR3				0x00008003
#define T_FOR4				0x00008004
#define T_FOR5				0x00008005
#define T_FOR6				0x00008006		// ���ʂׂ̈����܂ŕK�v
#define T_FORX				0x0000800f

#define T_STRUCT			0x00010000		// "struct"
#define T_STRUCT1			0x00010001
#define T_STRUCT2			0x00010002
#define T_STRUCT3			0x00010003
#define T_STRUCT4			0x00010004
#define T_STRUCT5			0x00010005
#define T_STRUCT6			0x00010006		// ���ʂׂ̈����܂ŕK�v
#define T_STRUCTX			0x0001000f

#define T_UNION				0x00020000		// "union"
#define T_UNION1			0x00020001
#define T_UNION2			0x00020002
#define T_UNION3			0x00020003
#define T_UNION4			0x00020004
#define T_UNION5			0x00020005
#define T_UNION6			0x00020006		// ���ʂׂ̈����܂ŕK�v

#define T_SHL				0x00040000		// <....>
#define T_SHL1				0x00040001
#define T_SHL2				0x00040002

#define T_CASE				0x00080000
#define T_CASE1				0x00080001
#define T_CASE2				0x00080002
#define T_CASE3				0x00080003
#define T_DEFAULT1			0x00080004
#define T_DEFAULT2			0x00080005
#define T_DEFAULT3			0x00080006

#define T_RETURN			0x00100000
#define T_RETURN1			0x00100001
#define T_RETURN2			0x00100002
#define T_RETURN3			0x00100003
#define T_RETURN4			0x00100004

#define T_TYPE				0x00200000		// �^�錾
// #define T_INT			0x00200001		// "int"
// #define T_CHAR			0x00200002		// "char"
// #define T_SHORT			0x00200003		// "short"
// #define T_LONG			0x00200004		// "long"
// #define T_BOOL			0x00200005		// "bool"
// #define T_VOID			0x00200006		// "void"
#define T_OTHER_TYPE		0x00200007		// ���̑�
// #define T_OTHER_TYPE2	0x00200008		// �����܂�type

#define T_DEFIF				0x00400000		// #if, #ifdef, #ifndef
#define T_DEF_IF1			0x00400001
#define T_DEF_IF2			0x00400002
#define T_DEF_ELSE			0x00400004		// #else
#define T_DEF_ELSE1			0x00400005
#define T_DEF_ELSE2			0x00400006
#define T_DEF_END			0x00400008		// #endif
#define T_DEF_END1			0x00400009
#define T_DEF_END2			0x0040000a

#define T_INCLUDE			0x00800000
#define T_INCLUDE1			0x00800001		// "#include"
#define T_INCLUDE2			0x00800002

#define T_DEFINE			0x01000000		// "#define"
#define T_DEFINE1			0x01000001
#define T_DEFINE2			0x01000002
#define T_DEFINE3			0x01000003
#define T_DEFINE4			0x01000004
#define T_DEFINEX			0x0100000f		// sub T_DEFINE

#define T_DEF_OTHER			0x02000000		// #xxxxx
#define T_DEF_OTHER1		0x02000001
#define T_DEF_OTHER2		0x02000002
#define T_DEF_OTHER3		0x02000003

#define T_DEF_ANO			0x04000000
#define T_DEF_ANO1			0x04000001

#define T_PRAGMA			0x08000000		// "#pragma"
#define T_PRAGMA1			0x08000001
#define T_PRAGMA2			0x08000002
#define T_PRAGMA3			0x08000003

#define T_MOJIS				0x10000001		// '����',"������"
#define T_DIGIT				0x10000002		// '����',"������"
#define T_OTHER				0x10000003		// ���̑�

#define T_CRLF				0x20000001		// CR,LF
#define T_PROC				0x20000002		// �֐�
#define T_MULTI				0x20000003		// ������(TAB�g�p�s��)
#define T_SEMIKOLON			0x20000004		// ';'
#define T_B_K_PAIR			0x20000005		// '{�`}'�̕�
#define T_YEN				0x20000006		// '\'����̕�

#define T_MASK_IN			0x40000000		// local
#define T_TYPE_IN			0x40000001		// "int" local
#define T_O_DEF_IN			0x40000002		// ���̑���define local
#define T_STRUCT_IN			0x40000004		// "struct" local
#define T_UNION_IN			0x40000005		// "union" local
#define T_OTHER_IN			0x40000006		// ���̑� local

// #define T_ETC			0x80000000		// ���̑�
#define T_TYPEDEF			0x80000001		// typedef
#define T_COM_MES			0x80000002		// program�̌�̺��Ăɍ��킹��(T_MES15�̑���)
#define T_COM1				0x80000003		// comment1
#define T_BIG_KAKKO			0x80000004		// '{', '}'
#define T_CALL				0x80000005		// call �֐�
#define T_ASM				0x80000006		// assembler
#define T_RENZOKU			0x80000007		// �O�s�̘A��
#define T_KAKKO				0x80000008		// '(', ')'

// --------------- sub TYPE ------------------------
#define S_INT				0x00000001		// "int"
#define S_INT_P				0x00000011		// "int *"
#define S_CHAR				0x00000002		// "char"
#define S_CHAR_P			0x00000012		// "char *"
#define S_SHORT				0x00000003		// "short"
#define S_SHORT_P			0x00000013		// "short *"
#define S_LONG				0x00000004		// "long"
#define S_LONG_P			0x00000014		// "long *"
#define S_FLOAT				0x00000005		// "float"
#define S_FLOAT_P			0x00000015		// float *"
#define S_VOID				0x00000006		// "void"
#define S_VOID_P			0x00000016		// "void *"
#define S_DOUBLE			0x00000007		// "double"
#define S_DOUBLE_P			0x00000017		// "doule *"
#define S_UNSIGNED			0x00000008		// "unsigned"
#define S_UNSIGNED_P		0x00000018		// "unsigned *"
#define S_SIGNED			0x00000009		// "signed"
#define S_SIGNED_P			0x00000019		// "signed *"
#define S_CSTRING			0x0000000a		// "Cstrong"
#define S_CSTRING_P			0x0000001a		// "Cstrong *"
// #define S_POINTER_P		0x0000001b		// "pointer"
#define S_OTHER_TYPE		0x000000ff		// ���̑�

// --------------- grobal group ------------------------
#define G_DEFINE			BIT0			// 0x00000001 "#define"
#define G_DEF_OTHER			BIT1			// 0x00000002 "#xxxxx"
#define G_IF				BIT2			// 0x00000004 "if()"
#define G_B_K_PAIR			BIT3			// 0x00000007 '{' �` '}'
#define G_OTHER				BIT4			// 0x00000010 ���̑�
// #define G_EXTERN			BIT5			// 0x00000020 extern
#define G_STRUCT1			BIT6			// 0x00000040 "struct"
#define G_STRUCT2			BIT7			// 0x00000080 "struct {}"
// #define G_UNION			BIT8			// 0x00000100 "union"
#define G_DIGIT				BIT9			// 0x00000200 ����
#define G_CASE				BIT10			// 0x00000400 case xx:
#define G_TYPEDEF			BIT11			// 0x00000800 typedef
#define G_INCLUDE			BIT12			// 0x00001000 #include
#define G_YEN				BIT13			// 0x00002000 '\'
#define G_TYPE_IN			BIT14			// 0x00004000 int, char, long, struct, union
#define G_ASM				BIT15			// 0x00008000 assembler
#define G_PROC				BIT16			// 0x00010000 proc
#define G_MOJIS				BIT17			// 0x00020000 ������

#define G_TYPE1				BIT28			// 0x10000000 �^�錾
#define G_TYPE2				BIT29			// 0x20000000 �^�錾 + {}

// --------------------- 1�O�̕������ ------------------------
#define C_MASK				0xffffff00

#define C_MASK_DEFIF		BIT8			// 0x00000100
#define C_DEF_IF			BIT8 + 1		// #if
#define C_DEF_ELSE			BIT8 + 2		// #else
#define C_ELIF				BIT8 + 3		// #elif
#define C_ENDIF				BIT8 + 4		// #endif
#define C_IFDEF				BIT8 + 5		// #ifdef
#define C_IFNDEF			BIT8 + 6		// #ifndef

#define C_MASK_OTHER_DEF	BIT9			// 0x00000200
#define C_INCLUDE			BIT9 + 1		// #include
#define C_PRAGMA			BIT9 + 2		// #pragma
#define C_UNDEF				BIT9 + 3		// #undef
// #define C_USE			BIT8 + 4		// #use
// #define C_FUSES			BIT8 + 5		// #fuses
#define C_DEF_OTHER			BIT9 + 6		// #xxxxx
#define C_DEF_ANOTHER		BIT9 + 7		// # xxxxx

#define C_MASK_TYPE1		BIT10			// 0x00000400 char, short, long....
#define C_INT				BIT10 + 0x01	// "int"
#define C_CHAR				BIT10 + 0x02	// "char"
#define C_SHORT				BIT10 + 0x03	// "short"
#define C_LONG				BIT10 + 0x04	// "long"
#define C_BOOL				BIT10 + 0x05	// "bool"
#define C_FLOAT				BIT10 + 0x06	// "float"
#define C_VOID				BIT10 + 0x07	// "void"
#define C_DOUBLE			BIT10 + 0x08	// "double"
#define C_NEW				BIT10 + 0x09	// "new"
#define C_DELETE			BIT10 + 0x0A	// "Delete"
#define C_STRING			BIT10 + 0x0B	// "string"

#define C_MASK_TYPE2		BIT11			// 0x00000800
#define C_USING				BIT11 + 0x01	// "using"
#define C_CONST				BIT11 + 0x02	// "const"
#define C_NAMESPACE			BIT11 + 0x03	// "namespace"
#define C_CLASS				BIT11 + 0x04	// "class"
#define C_PRIVATE			BIT11 + 0x05	// "private"
#define C_PROTECTED			BIT11 + 0x06	// "protected"
#define C_FAR				BIT11 + 0x07	// "far"
#define C_DEFINED			BIT11 + 0x08	// "defined"
#define C_STATIC			BIT11 + 0x09	// "static"
#define C_PUBLIC			BIT11 + 0x0a	// "public"
#define C_VOLATILE			BIT11 + 0x0b	// "volatile"
#define C_EXTERN			BIT11 + 0x0e	// "extern"
#define C_UNSIGNED			BIT11 + 0x0f	// "unsigned"
#define C_SIGNED			BIT11 + 0x10	// "signed"

#define C_MASK_ENZAN		BIT12			// 0x00001000 ���Z
#define C_KOME				BIT12 + 1		// ���Z "*"
#define C_SURA				BIT12 + 2		// ���Z "/"
#define C_PLUS				BIT12 + 3		// ���Z "+"
#define C_MINUS				BIT12 + 4		// ���Z "-"
#define C_AMARI				BIT12 + 5		// ���Z "%"
#define C_W_KOME			BIT12 + 6		// ���Z "**"

#define C_MASK_RONRI		BIT13			// 0x00002000 �_�����Z
#define C_AND				BIT13 + 1		// �_�����Z "&"
#define C_OR				BIT13 + 2		// �_�����Z "|"
#define C_XOR				BIT13 + 3		// �_�����Z "^"
#define C_HANTEN			BIT13 + 4		// �_�����Z "~"
#define C_DOKI				BIT13 + 5		// �_�����Z "!"

#define C_COM				BIT14			// 0x00004000 ���� "//","/*"
#define C_COM1				BIT14 + 1		// ���� "//"
#define C_COM2				BIT14 + 2		// ���� "/*"
#define C_COM3				BIT14 + 3		// ���� "*/"

#define C_MASK_OTHER		BIT15			// 0x00008000 ���̑�
#define C_KOMMA				BIT15 + 1		// ,
#define C_DOT				BIT15 + 2		// .
#define C_SEMIKOLON			BIT15 + 3		// ;
#define C_KOLON				BIT15 + 4		// :
#define C_SMOJI				BIT15 + 5		// '
#define C_WMOJI				BIT15 + 6		// "
#define C_MID_STRUCT		BIT15 + 7		// ->
#define C_CR				BIT15 + 8		// _CR
#define C_LF				BIT15 + 9		// _LF
#define C_IQUAL				BIT15 + 10		// ���� "="
#define C_GOTO				BIT15 + 11		// goto
#define C_QUESTION			BIT15 + 12		// ?
#define C_YEN				BIT15 + 13		// '\'
#define C_WKOLON			BIT15 + 14		// ::
#define C_SHL				BIT15 + 15		// <
#define C_SHR				BIT15 + 16		// >

#define C_MASK_MID_K		BIT16			// 0x00010000
#define C_MID_K_L			BIT16 + 1		// [
#define C_MID_K_R			BIT16 + 2		// ]

#define C_MASK_BIG_K		BIT17			// 0x00020000
#define C_BIG_K_L			BIT17 + 1		// {
#define C_BIG_K_R			BIT17 + 2		// }

#define C_MASK_KAKKO		BIT18			// 0x00040000
#define C_K_L				BIT18 + 1		// (
#define C_K_R				BIT18 + 2		// )

#define C_MASK_FUKUGO		BIT19			// 0x00080000 �����L��
#define C_P_IQUAL			BIT19 + 1		// +=
#define C_MID_IQUAL			BIT19 + 2		// -=
#define C_MUL_IQUAL			BIT19 + 3		// *=
#define C_DIV_IQUAL			BIT19 + 4		// /=
#define C_AMARI_IQUAL		BIT19 + 5		// %=
#define C_AND_IQUAL			BIT19 + 6		// &=
#define C_OR_IQUAL			BIT19 + 7		// |=
#define C_XOR_IQUAL			BIT19 + 8		// ^=
#define C_LESS_IQUAL		BIT19 + 9		// <=
#define C_THAN_IQUAL		BIT19 + 10		// >=
#define C_DOKI_IQUAL		BIT19 + 11		// !=
#define C_SHL_IQUAL			BIT19 + 12		// <<=
#define C_SHR_IQUAL			BIT19 + 13		// >>=

#define C_MASK_W_ENZAN		BIT20			// 0x00100000 ���Z
#define C_W_PLUS			BIT20 + 2		// ���Z "++"
#define C_W_MINUS			BIT20 + 3		// ���Z "--"
#define C_W_AND				BIT20 + 4		// �_�����Z "&&"
#define C_W_OR				BIT20 + 5		// �_�����Z "||"
#define C_W_SHL				BIT20 + 6		// <<
#define C_W_SHR				BIT20 + 7		// >>
#define C_W_IQUAL			BIT20 + 8		// ���� "=="

#define C_STRUCT			BIT21			// 0x00200000 "struct"

#define C_UNION				BIT22			// 0x00400000 "union"

#define C_DEFINE			BIT23 + 1		// 0x00800001 "#define"
#define C_IF				BIT23 + 2		// "if"
#define C_ELSE				BIT23 + 3		// "else"
#define C_SWITCH			BIT23 + 4		// "switch"
#define C_CASE				BIT23 + 5		// "case"
#define C_DEFAULT			BIT23 + 6		// "default"
#define C_FOR				BIT23 + 7		// "for"
#define C_WHILE				BIT23 + 8		// "while"
#define C_DO				BIT23 + 9		// "do"
#define C_TRY				BIT23 + 10		// "try"
#define C_RETURN			BIT23 + 11		// "return"
#define C_SIZEOF			BIT23 + 12		// "sizeof"
#define C_TRUE				BIT23 + 13		// "true"
#define C_FALSE				BIT23 + 14		// "false"
#define C_TEMPLATE			BIT23 + 15		// "template"
#define C_ASM				BIT23 + 16		// "asm"
#define C_ENDASM			BIT23 + 17		// "endasm"
#define C_CALL				BIT23 + 18		// call(�֐�)
#define C_TYPEDEF			BIT23 + 19		// "typedef"

// #define C_SHARP			BIT24 + 1		// 0x01000001 "#"
#define C_WSHARP			BIT24 + 2		// 0x01000002 "##"

#define C_MACRO_TYPEDEF		BIT25			// 0x02000000 typedef xxxx yyyy

#define C_HAIRETU			BIT26			// 0x04000000 �z��

#define C_DIGIT				BIT28			// 0x10000000 ����
#define C_DIGITF			BIT28 + 1		// ���������_
#define C_DIGITH			BIT28 + 2		// 16�i�� intel HEX
#define C_DIGITX			BIT28 + 3		// 16�i��

#define C_ILLEGAL			BIT29			// 0x20000000 ���̑�(��@����, �������œ�)
#define C_OTHER				BIT30			// 0x40000000 ���̑�(�ϐ�, �֐� etc)
// #define C_POINTER		BIT31			// 0x80000000 pointer

// ------------------ �⏕flag -------------------------------
#define H_MASK_MES			0x000000ff		// 0x000000ff 1�s����
#define H_MES11				BIT0			// 0x00000001 "//"+TAB+message(program�|�󂠂�) �s����"//"�ǉ��K�v
// #define H_MES12			BIT1			// 0x00000002 TAB+"//"+message(program�|�󂠂�) TAB���"// "�ǉ��K�v
// #define H_MES13			BIT2			// 0x00000004 "// "+message(program�|�󂠂�) �s����"//"�ǉ��K�v
#define H_MES14				BIT4			// 0x00000010 "//"+TAB+message(program�|��Ȃ�) �s����"//"�ǉ��K�v
#define H_MES15				BIT5			// 0x00000020 TAB+"//"+message(program�|��Ȃ�) TAB���"// "�ǉ��K�v
#define H_MES16				BIT6			// 0x00000040 "//"+message(program�|��Ȃ�) �s����"//"�ǉ��K�v
#define H_MES17				BIT7			// 0x00000080 ���čs�B�����̂܂܉������Ȃ�

#define H_MES_E				BIT8			// 0x00000100 �Ō�ɺ���("//")����
#define H_IQUAL				BIT9			// 0x00000200 =
#define H_QUESTION			BIT10			// 0x00000400 ?
#define H_YEN1				BIT11			// 0x00000800 \�ő��s�̍s
#define H_YEN2				BIT12			// 0x00001000 \�̑O�s�ɑ��s�̑���
#define H_B_K_PAIR			BIT13			// 0x00002000 �P�s��{}����
#define H_BIG_K_L			BIT14			// 0x00004000 {����
#define H_BIG_K_R			BIT15			// 0x00008000 }����
#define H_STRUCT			BIT16			// 0x00010000 struct���̐錾
#define H_UNION				BIT17			// 0x00020000 union���̐錾
// #define H_MULTI_OTHER	BIT18			// 0x00040000 ���̑�+���̑�����
#define H_CASE				BIT19			// 0x00080000 case��(chk_line�Ŏg�p)
#define H_DEFAULT			BIT20			// 0x00100000 case��(chk_line�Ŏg�p)
#define H_ASM				BIT21			// 0x00200000 assembler
// #define H_EXTERN			BIT22			// 0x00400000 extern

// #define H_ERROR			BIT30			// 0x40000000 �װ����
// #define H_WARNING		BIT31			// 0x80000000 �x������

// ------------------ fdata.status -------------------------------
#define ST_SPACE			BIT0			// 0x00000001 ��߰��L��
#define ST_TAB				BIT1			// 0x00000002 TAB�L��
#define ST_PAIR_L			BIT2			// 0x00000004 �߱����� '{'�ʒu
#define ST_PAIR_R			BIT3			// 0x00000008 �߱����� '}'�ʒu
#define ST_PAIR_IN			BIT4			// 0x00000010 �߱����� "{}"�̒��ʒu
#define ST_COM				BIT5			// 0x00000020 ���Ĉʒu
#define ST_FINISH			BIT6			// 0x20000000 omment��TAB����I��

// --------------------------------------------------------------
#define MAX_SRC_NAME_LEN	100
#define MAX_END_MAP			256
#define MAX_PATH_LEN		200

// ------------- �ϐ� -------------------------------------------
#ifdef __RENEW__
#define EXTERN

char		hex_map[] = "0123456789ABCDEF";
EXTERN char debug_name2[] = "renew_debug2.txt";

#else
#define EXTERN	extern

extern char		versions[];
extern char		hex_map[];
extern char		debug_name2[];

#endif

// -------------------------------------------------------------------
EXTERN FILE		*fp_src;
EXTERN FILE		*fp_err;
EXTERN FILE		*ini_fp;

// -------------------------------------------------------------------
EXTERN char		*disp;											// 1�s����buff

// ----------------------------------------------------------
EXTERN char		src_name[MAX_SRC_NAME_LEN];						// ����̧�ٖ�
EXTERN char		new_name[MAX_SRC_NAME_LEN];						// �t������ؽĂ�̧�ٖ�prefix
EXTERN char		tmp_name[MAX_SRC_NAME_LEN];						// �ꎞ�I��save����̧�ٖ�
EXTERN char		err_name[MAX_SRC_NAME_LEN];						// erroŗ�ٖ�
EXTERN char		ini_name[MAX_SRC_NAME_LEN];						// ������̧�ٗp
EXTERN char		exe_name[MAX_SRC_NAME_LEN];						// renew��̧�ٖ�
EXTERN char		old_name[MAX_SRC_NAME_LEN];						// rename�p
EXTERN char		path_in_name[MAX_PATH_LEN];
EXTERN char		file_in_name[MAX_SRC_NAME_LEN];
EXTERN char		ext_in_name[MAX_SRC_NAME_LEN];
EXTERN char		cur_path_name[MAX_PATH_LEN];					// ������̓���̧�ٖ�
EXTERN char		src_full_name[MAX_PATH_LEN + MAX_SRC_NAME_LEN]; // ����̧�ٖ������߽��(�װ�o�͗p)
EXTERN char		*cut_buf;										// �޲�ذ������ޯ̧
EXTERN char		*load_buf;										// �޲�ذ��۰�ނ����ޯ̧
EXTERN char		*v_buf;											// setvbuf()���g���ē��o�͂�������
EXTERN char		r_buf[CHAR_SIZE2];								// ���1�s��荞��buf
EXTERN char		w_buf[CHAR_SIZE2];								// 1�s��������buf
EXTERN char		big_buf[LOADSIZE];								// 1�s��������buf

// --------------- parameter ---------------------------
EXTERN int		font_type;										// 0:����, 1:utf8, 2:Shift JIS
EXTERN int		form_all;										// -cx �` -gx �̗L���w��
EXTERN int		form_source_name;								// ������̏��� 0:������͕ς�炸+.new��V�K�ɍ��, 1:�������+.old�Ƃ���\n",
EXTERN int		form_define_tab;								// #define �̑�1�Ԗڒ�`�Ƒ�2�ԖڊԒ萔��TAB�ʒu
EXTERN int		form_define_com_tab;							// #define �̺��Ă�TAB�ʒu
																// 0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2�`:�ő�TAB�ʒu
EXTERN int		form_other_com_tab;								// �֐����̺��Ĉʒu��TAB�ʒu
																// 0:�������Ȃ�, 1:TAB�Ȃ�(��߰��̂�), 2�`:�ő�TAB�ʒu
EXTERN int		form_global_int_tab;							// ���ϐ���int, char, long, unsigned��TAB�ő����� 0:���Ȃ�, 1:����
EXTERN int		form_local_int_tab;								// ۰�ٕϐ���int, char, long, unsigned��TAB�ő����� 0:���Ȃ�, 1:����
EXTERN int		form_big_kakko_pair;							// '{'�`'}'��TAB�̈ʒu�����낦��
EXTERN int		form_kolon;										// ��݂̑O��̽�߰�
EXTERN int		form_cut_comment;								// ���Ă��폜����.
																// 0:�폜���Ȃ�
																// BIT0:�{���̉E���̒���(//�`)���폜����
																// BIT1:�{�����̕�������(/*�`*/)���폜����
																// BIT2:���čs(//�`)���폜����
																// BIT3:���čs(/*�`, �`*/)���폜����
EXTERN int		form_long_comment;								// "/*"�Ŏn�܂钷�����͂�S��"//"�ɕϊ�
																// 0:�ϊ����Ȃ�, 1:�ϊ�����, 2:�ł��邾���|�������
EXTERN int		form_comment_prog;								// ���Ē��ł��ł������|�󂷂�
																// 0:�S�ĺ��ĂƂ��Ĉ���, 1:TAB�̂ݒ�������, 2:�ł��邾���|�󂷂�
EXTERN int		form_kakko_space;								// ���ʂ̑O����߰��ɂ���
																// 0:�A�����銇�ʂͽ�߰������Ȃ�, 1:���ʂ̓����ͽ�߰�������
EXTERN int		form_ifdef_mode;								// #if, #else, #endif ��`
EXTERN int		form_limit_line;								// '{�`}'�Ԃ�TAB�𖳌��ɂ���P�s�̕�����
EXTERN int		form_yen;										// "\"�̏��� 0:�������Ȃ�, 1:TAB��������
EXTERN int		form_struct_big_kakko;							// struct/union ��'{'�`'}'�̏���
EXTERN int		form_if_big_kakko;								// if ��'{'�`'}'�̏���
EXTERN int		form_else_big_kakko;							// else ��'{'�`'}'�̏���
EXTERN int		form_for_big_kakko;								// for ��'{'�`'}'�̏��� �Œ�
EXTERN int		form_while_big_kakko;							// while ��'{'�`'}'�̏��� �Œ�
EXTERN int		form_do_big_kakko;								// do ��'{'�`'}'�̏��� �Œ�
EXTERN int		form_try_big_kakko;								// try ��'{'�`'}'�̏��� �Œ�
EXTERN int		form_switch_big_kakko;							// switch ��'{'�`'}'�̏��� �Œ�
EXTERN int		form_other_big_kakko;							// ���̑� ��'{'�`'}'�̏��� �Œ�
EXTERN int		form_typedef_mode;								// typedef ��`
EXTERN int		form_utf8_mode;									// 0:����, 1:utf8, 2:Shit JIS
// EXTERN int	form_zenkaku;									// 0:�Ȃ�, 1:���p���ł�S�p���łɕς���, 2:�S�p���ł𔼊p���łɕς���(���Ă̂�)
EXTERN int		debug_mode;										// debug�p

// ----------------------------------------------------------
EXTERN int		max_line;
EXTERN int		max_fdata_line;									// �m�ۂ���max memory�s��

// ----------------------------------------------------------
EXTERN int		ope_type;										// 1�s���s���̖���
EXTERN int		ope_cnt;										// 1�s�̏����� �� if( abcd == 0 )
																//                �@�A �B  �C �D�E <-- ope_cnt=6
EXTERN int		kakko_cnt;										// ���ʂ̐�. '('��+1, ')'��-1
EXTERN int		big_kakko_cnt;									// �劇�ʂ̐�. '{'��+1, '}'��-1
EXTERN int		space_cut_flag;									// 1:���̕�����' '�����Ȃ�
EXTERN int		next_space_cut;									// ���̕�����space���ȗ�����
EXTERN int		crlf_cnt;										// �A�������s�̐�
EXTERN int		src_line_no;									// ����scnt
EXTERN int		r_pos, tab_pos;
EXTERN int		before_r_pos;
EXTERN int		total_err_cnt;									// �װ�s�̶��� 100�s�𒴂�����L�^���Ȃ�
EXTERN int		tab_stack_cnt;									// TAB��stack�Ǘ��p real�ʒu

EXTERN int		tmp_moji_type;									// �ꎞ�I�Ȍ��݂�moji_type
EXTERN int		cur_moji_type;									// ���݂�moji_type
EXTERN int		before_c_type1;									// 1�O��moji_type
EXTERN int		before_c_type2;									// 2�O��moji_type
EXTERN int		before_c_type3;									// 3�O��moji_type
EXTERN int		comment_line;									// 1:1�O�̺��čs, 2:1�s�̺���, 3:�A������

EXTERN int		before_type;									// 1�O��if���̌����p
EXTERN int		before_ope_type;
EXTERN int		before_tab_pos;									// ���čs�̑O��TAB�ʒu
EXTERN int		before_tab_pos2;								// fdata->tab_pos ���čs�̑O��TAB�ʒu
EXTERN int		before_big_kakko_cnt;
EXTERN int		before_kakko_cnt;
EXTERN int		before_back_line_type;
EXTERN int		before_hojo_flag;
EXTERN int		before_tab_stack_cnt;
EXTERN int		before_finish_flag;
EXTERN int		before_if_stack_top;

EXTERN int		if_stack_top;									// if()��save�ʒu��top

EXTERN int		repeat_flag;									// 1:get_tok()�����Ȃ��ŁA�����ް����g��
// EXTERN int	line_type;										// �s�̎��
EXTERN int		back_line_type;									// �O�s�̎��
EXTERN int		finish_flag;									// 1 loop�������I�������=1
EXTERN int		debug_n;										// debug���Ɏg���ϐ� n
EXTERN int		para_cnt;										// ���Ұ���
EXTERN int		typedef_cnt;
EXTERN int		pos_map[MAX_END_MAP];							// max TAB�ʒu�v�Z�p
EXTERN int		total_pos[MAX_END_MAP];							// TAB�ʒu�v�Z�p
EXTERN int		c_map[MAX_C_MAP];								// C����ނ̕���pbuf
// EXTERN int	total_pos_src[MAX_END_MAP];

// ----------------------------------------------------------
EXTERN struct TAB_STACK_S tab_stack[MAX_TAB_STACK];			// tab�̈ʒu
EXTERN struct TAB_STACK_S tab_back_stack[MAX_TAB_STACK];	// ���ē��p��backup
EXTERN struct FDATA *ope_buf, *fdata;						// 1�s�����ް�̧�ٍ\����
EXTERN struct MULTI_NAME_S src_name_buf[MAX_SRC_NAME_LEN];
EXTERN struct TYPEDEF_S typedef_map[MAX_TYPEDEF_CNT];
EXTERN struct IF_STACK_S if_tab_stack[MAX_TAB_STACK];		// if()�̈ʒu
EXTERN struct IF_STACK_S if_back_stack[MAX_TAB_STACK];		// ���ē��p��backup

// ------------- �ȗ��^̧�ٱ��� -------------
#define Ropen( name ) { \
		fp_src = fopen( name, "rb" ); \
		if( fp_src == NULL ) { printf( "Fatal: can't open file:%s\n", name ); wait_exit( 1 ); } \
	}

#define Wopen( name ) { \
		fp_dst = fopen( name, "wb" ); \
		if( fp_dst == NULL ) { printf( "Fatal: can't create file:%s\n", name ); wait_exit( 1 ); } \
	}

#define Read( buf, siz )	fread( buf, 1, siz, fp_src )
#define Write( buf, siz )	fwrite( buf, 1, siz, fp_dst )

#define Rseek( ptr )		fseek( fp_src, ptr, 0 )
