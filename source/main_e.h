void obj_hex2( int obj_data, char *wr_buf );
int hex_bin( int char_data );
int hex_binn( char *s_buf );
int pass_space( char *s_buf );
int getln( FILE *fp, char *d_buf, int max_len );
void close_all( void );
void wait_exit( int ret_no );
void save_error_file( char *mes_err );
void err_trap( int mode, int err_no, char *mes_buf, char *path_name );
void err_trap_line( int mode, int err_no, char *s_buf );
void usage( void );
void disp_debug_para0( void );
void disp_debug_para1( void );
void disp_debug_para2( char *d_buf );
int get_cur_path_name( char *p_name, int len );
int get_def_tok( char *d_buf, char *s_buf, int *tok_len );
void make_ini_file( void );
void para_sub( char command, int para );
void parameter_all( int type, char *line_buf );
void analize_ini_file( int mode );
int bunri_path( char *s_buf, char *p_name, char *f_name, char *e_name );
void check_para( int argc );
void analize_inline( char *s_buf );
void src_input_name( void );
int search_src_name( LPCSTR s_name );
int main( int argc, char **argv );
