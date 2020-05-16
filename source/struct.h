// -------------------------------------------------------------------
// struct.h
// -------------------------------------------------------------------
// PE形式実行ﾌｧｲﾙのﾍｯﾀﾞｰﾌｧｲﾙ
// ---------------------------------------------------------------------
typedef unsigned char	Uchar;
typedef unsigned short	Ushort;
typedef unsigned int	Uint;
typedef unsigned long	Ulong;

typedef unsigned char	u8;		// /<  8-bit unsigned integer
typedef unsigned short	u16;	// /< 16-bit unsigned integer
typedef unsigned int	u32;	// /< 32-bit unsigned integer
typedef unsigned long	u64;	// /< 64-bit unsigned integer

typedef char			s8;		// /<  8-bit signed integer
typedef short			s16;	// /< 16-bit signed integer
typedef int				s32;	// /< 32-bit signed integer
typedef long			s64;	// /< 64-bit signed integer

// -------------------------------------------------------------------
#define CHAR_SIZE		384		// 1行取り込みﾊﾞｯﾌｧ ｻｲｽﾞ
#define CHAR_SIZE2		1024	// 1行書き込みﾊﾞｯﾌｧ ｻｲｽﾞ 2020.05.04
#define BUF_SIZE		1024	// 使用するﾊﾞｯﾌｧ
#define LOADSIZE		0x10000 // 一度にﾛｰﾄﾞ可能なｻｲｽﾞ
#define MAX_TAB_STACK	256		// TABの最大深さ
#define MAX_CHAR_LEN	32		// 変数の最大文字数
#define MAX_TEIGI_NO	32		// 0:top, 1:定義, 2:定数1, 3:定数2 ....
#define MAX_C_MAP		100		// ｺﾒﾝﾄ行がﾌﾟﾛｸﾞﾗﾑかの検査用
#define JUDGE_PERCENT	51		// ｿｰｽのTABの分布の判定値(%)
#define MAX_TYPEDEF_CNT 50		// typedefの最大登録ﾏｸﾛ数
#define MAX_TYPEDEF_LEN 36		// typedefの最大登録文字列数

// -------------------------------------------------------------------
struct TAB_STACK_S {
	int ope_type;		// 実行中のope_type
	int tab_pos;		// 実行中のTAB位置
	int tab_pos2;		// 	fdata->tab_pos 実行中のTAB位置
	int kakko_cnt;		// 括弧の数
	int line_type;
	int back_line_type; // '('~')'の不連続で使用
	int big_kakko_cnt;	// '{'.']}の数
	int finish_flag;	// loop処理
	int tag_point;		// 一括戻るﾎﾟｲﾝﾄ位置
	int if_flag;		// if()文 = 1
};
// ---------------------------------------------------------------------
struct IF_STACK_S {
	int tab_pos;
	int tag_point; // 一括戻るﾎﾟｲﾝﾄ位置
};
// ---------------------------------------------------------------------
struct B_MAP_S {
	int		type;		// 文字のtype
	char	name[12];	// 文字列名(max9以上)
	int		len;		// nameの長さ(作業用)
};
// ---------------------------------------------------------------------
struct FDATA { // ﾃﾞｰﾀﾌｧｲﾙ構造体(TABはｽﾍﾟｰｽに換算)
	int		src_line_no;				// ｿｰｽの行番号(1行目から)
	int		line_type;					// その行の内容(#define, #include, typedef, struct など)
	int		sub_type;					// その行の詳細内容(int, char, long * など)
	int		ope_type;					// operation No.
	int		tab_pos;					// TABのoffset(4文字TAB)
	int		tab_pos2;					// fdata->tab_pos 実行中のTAB位置
	int		hojo_flag;					// BIT単位
	int		debug_joho;					// degu用の表示ﾃﾞｰﾀ
	int		big_kakko_cnt;				// '{','}'count。
	int		com_teigi_no;				// ｺﾒﾝﾄ開始位置のteigi_no
	int		pair_teigi_top;				// teigi_no offset で使う
	int		pair_teigi_end;				// teigi_no offset で使う
	int		status[MAX_TEIGI_NO];		// 本文用 ｽﾍﾟｰｽ有効, TAB有効, ﾍﾟｱｰ括弧 '{'位置, ﾍﾟｱｰ括弧 '}'位置, ﾍﾟｱｰ括弧 "{}"の中位置
	int		top_pos[MAX_TEIGI_NO];		// 文節の最初の位置
	int		block_len[MAX_TEIGI_NO];	// 分節の長さ
//	int		src_pair_kakko_top;			// '{'〜'}'の'{'のｿｰｽ位置
	int		src_pair_kakko_end;			// '{'〜'}'の'}'のｿｰｽ位置
	int		src_last_pos;				// ｺﾒﾝﾄ前の最後の位置(TABをｽﾍﾟｰｽに換算)
	int		src_com_pos;				// ｺﾒﾝﾄの位置
	int		head_space_len;				// ｿｰｽの最初の文字までのｽﾍﾟｰｽ(TAB=4)
	char	pri_comment[CHAR_SIZE];		// 最初のｺﾒﾝﾄ分("/*〜*/")
	char	mes[CHAR_SIZE];				// 成型した本文
};
// -------------- debug用表示file命令 -----------------------------------------
struct S_TYPE {
	Uint t_type;
	char name[12];
};
// ---------------------------------------------------------------------
struct MULTI_NAME_S {
	char name[200]; // 文字列名
};
// ---------------------------------------------------------------------
struct BUNPU_S {
	int cnt;		// 数量
	int line_no;	// 行番号
};
// ---------------------------------------------------------------------
struct SUKEI_S {
	int cnt;		// 数量
	int hensachi;	// 偏差値
};
// ---------------------------------------------------------------------
struct KAKKO_MAPS {
	int kakko_cnt;
	int pos;
	int c_type;
	int tag_pos;
};
// ---------------------------------------------------------------------
struct TYPEDEF_S {
	int		type;					// 数量
	char	name[MAX_TYPEDEF_LEN];	// 偏差値
};
