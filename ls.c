#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_STRLEN 256


typedef struct  {

    char d_name[MAX_STRLEN];
    int l;
    int R;
    int a;
    int p;
    int r;

} config_t;



int ls(config_t* config, int depth);

int dirent_compare(const void* da, const void* db);
int dirent_compare_reverse(const void* da, const void* db);

void print_files(const config_t* config, struct dirent** entries, int size);
void print_file(const config_t* config, struct dirent* entry);
void print_file_attribs(const config_t* config,struct dirent* entry, struct stat* buffer);

void parse_args(config_t* config, int argc, char** argv);
void parse_opts(config_t* config,const char* opts);

int dir_children_amt(const config_t* config);

int dir_contents(const config_t* config, struct dirent*** entries);


int main(int argc, char* argv[]) {


    config_t config;

    parse_args(&config, argc, argv);


    return ls(&config, 0);

}

void parse_opts(config_t* config,const char* opts){

    opts++;


    while(*opts != '\0'){


        switch(*opts){

            case 'a':
                config->a = 1;
                break;
            case 'p':
                config->p = 1;
                break;
            case 'l':
                config->l = 1;
                break;
            case 'R':
                config->R = 1;
                break;
            case 'r':
                config->r = 1;
                break;
            case '\0':
                break;

        }

        opts++;

    }





}


int dirent_compare(const void* da, const void* db){

    struct dirent* _da = *(struct dirent**) da;
    struct dirent* _db = *(struct dirent**) db;

    return strcmp(_da->d_name,_db->d_name);

}

int dirent_compare_reverse(const void* da, const void* db){

    struct dirent* _da = *(struct dirent**) da;
    struct dirent* _db = *(struct dirent**) db;

    return strcmp(_db->d_name,_da->d_name);

}


void print_files(const config_t* config, struct dirent** entries,  int size){


    for(int i = 0; i < size; i++){


        print_file(config,entries[i]);


    }


}

int dir_children_amt(const config_t* config){

    DIR* directory;
    struct dirent* entry;

    directory = opendir(".");
    if(directory == NULL) return -1;

    entry = readdir(directory);
    int size = 0;

    while(entry != NULL){


        size++;

        entry = readdir(directory);
    }

    closedir(directory);
    return size;

}


 int dir_contents(const config_t* config, struct dirent*** entries){

    DIR* directory;
    struct dirent* entry;


    directory = opendir(".");
    if(directory == NULL) return -1;

    int size = dir_children_amt(config);

    if(size == 0) return 0;
    int ix = 0;

    *entries = (struct dirent**) malloc(size * sizeof(struct dirent*));


    entry = readdir(directory);


    while(entry != NULL){



        (*entries)[ix++] = entry;

        entry = readdir(directory);

    }

    closedir(directory);

    if(config->r){

        qsort(*entries, size, sizeof(struct dirent**),dirent_compare_reverse);

    } else {

        qsort(*entries, size, sizeof(struct dirent**),dirent_compare);

    }



    return size;

}


void parse_args(config_t* config, int argc, char** argv){

    config->l = 0;
    config->R = 0;
    config->a = 0;
    config->p = 0;
    config->r = 0;


    for(int i = 1; i < argc; i++){

        char* command = argv[i];
        if(command[0] == '-'){

            parse_opts(config,command);

        } else {

            strcpy(config->d_name, command);
            chdir(config->d_name);

        }

    }

}



int ls(config_t* config, int depth){

    struct dirent** entries = NULL;

//    if(depth == 6) return -1;

    int size = dir_contents(config,&entries);

    if(size == -1){

        return -1;

    }

    if(config->R){

        for(int i = 0; i < size; i++){

            char cwd[MAX_STRLEN];

            const char* const d_name = entries[i]->d_name;

            if(strcmp(d_name, ".") == 0 || strcmp(d_name, "..") == 0) continue;
            if(d_name[0] == '.' && !config->a) continue;


            for(int j = 0; j < depth; j++){

                printf("\t");

            }

            struct stat buffer;

            int r = stat(d_name, &buffer);

            if(r == -1) return 0;




            print_file(config,entries[i]);


            if(S_ISDIR(buffer.st_mode)){

                chdir(d_name);

                ls(config,depth+1);

                chdir("..");
                free(entries);

                size = dir_contents(config,&entries);

            }

        }

    } else {

        print_files(config,entries,size);

    }

    free(entries);


    return 0;

}

void print_file(const config_t* config, struct dirent* entry){

    struct stat buffer;

    int ret = stat(entry->d_name,  &buffer);
    if(ret == -1) return ;

    if(!config->a && entry->d_name[0] == '.'){

        return;

    }

    if(config->l && !config->R){

        print_file_attribs(config,entry, &buffer);

    }

    if(S_ISDIR(buffer.st_mode) && config->p){

        printf("/%s ", entry->d_name);

    } else {

        printf("%s ", entry->d_name);

    }

    if(config->R || config->l){

        printf("\n");

    }

}

void print_file_attribs(const config_t* config,struct dirent* entry, struct stat* buffer){



    struct passwd *pw = getpwuid(buffer->st_uid);
    struct group  *gr = getgrgid(buffer->st_gid);


    printf( (S_ISDIR(buffer->st_mode)) ? "d" : "-");
    printf( (buffer->st_mode & S_IRUSR) ? "r" : "-");
    printf( (buffer->st_mode & S_IWUSR) ? "w" : "-");
    printf( (buffer->st_mode & S_IXUSR) ? "x" : "-");
    printf( (buffer->st_mode & S_IRGRP) ? "r" : "-");
    printf( (buffer->st_mode & S_IWGRP) ? "w" : "-");
    printf( (buffer->st_mode & S_IXGRP) ? "x" : "-");
    printf( (buffer->st_mode & S_IROTH) ? "r" : "-");
    printf( (buffer->st_mode & S_IWOTH) ? "w" : "-");
    printf( (buffer->st_mode & S_IXOTH) ? "x" : "-");

    printf(" %s %s",pw->pw_name, gr->gr_name);

    printf(" %lld", buffer->st_size);

//    char date[13];
//    strftime(date, 13, "%b %d %H:%M", gmtime(&(buffer->st_ctime)));
//    printf(" %s", date);

    printf(" ");

}