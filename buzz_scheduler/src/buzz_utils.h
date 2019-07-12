#ifndef BUZZ_UTILS_H
#define BUZZ_UTILS_H

extern int buzz_listen(const char* type,
                       int msg_size,
                       const char* port);

extern int buzz_script_set(const char* bo_filename,
                           const char* bdbg_filename);

extern void buzz_script_step();

extern void buzz_script_destroy();

extern int buzz_script_done();

#endif
