#include "../libmx/inc/libmx.h"

#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <sys/acl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>

#define COLOR_RESET "\x1b[0m"
#define COLOR_DIR "\x1b[34m"
#define COLOR_EXEC "\x1b[31m"



void mx_get_flags(int argc, char *argv[], char **flags);
typedef struct flags {
    bool R, a, A, G, h, dog, e, T, longf, one, C, r, t, u, c, S, files_and_flags, file_o;
    t_list *files;
    t_list *folders;
}   flags_t;
typedef bool (*SortComparator)(void *, void *);
typedef void (*OutputFunction)(t_list *, flags_t *, t_list *);



flags_t* mx_init_flags(char **flags_str, int argc);
void mx_flag_error(flags_t **flags, char flag_symbol);
void mx_sys_error(const char* str);
void mx_printlong(long num);
void mx_simple_output(t_list *files, flags_t *flags, t_list *path);
void mx_output_with_flag_one(t_list *files, flags_t *flags, t_list *path);
SortComparator mx_choose_sort(flags_t *flags);
t_list *mx_get_files(char *path, flags_t *flags);
void mx_uls(flags_t *flags, char *path, OutputFunction output, bool title);
OutputFunction mx_get_output(flags_t *flags);
bool mx_abccmp(void *s1, void *s2);
bool mx_check_file(char *path, flags_t *flags);
char *mx_get_filename(char *str);
bool mx_sizecmp(void *f1, void *f2);
void mx_print_filename(const char *name, const char *full_path, flags_t *flags);
void mx_file_error(const char *wrong_directory);
void mx_output_long(t_list *files, flags_t *flags, t_list *path);
char *mx_get_permissions(mode_t mode);
bool mx_timecmp(void *f1, void *f2);
void mx_reverse_list(t_list **head);
bool mx_lastmodcmp(void *f1, void *f2);
bool mx_lastchangcmp(void *f1, void *f2);
int mx_calc_spaces(int max_len);
void mx_list_clear(t_list **list);
