#include "ServerClient.h"

int main() {
  int ret, nbytes;
  mqd_t mqid;
  struct mq_attr attrib;
  struct stat sb;
  attrib.mq_msgsize = 256;
  attrib.mq_maxmsg = 10;
  
  mqid = mq_open("/mque", O_CREAT | O_RDWR, 0666, &attrib);
  if (mqid < 0) {
    printf("unable to open");
    exit(1);
  }

  char str[20] = "hello.c";
  
  ret = mq_send(mqid, str, 20, 5);
  if (ret < 0) {
    printf("unable to send");
    exit(2);
  }

  int maxlen = 256, prio;
  nbytes = mq_receive(mqid, (char *)&sb, 1024, &prio);
  if (nbytes < 0) {
    perror("unable to receiver");
    exit(2);
  }

  printf("File Attributes\n");
  printf("ID of device containing file : %ld\n", (long)sb.st_dev);
  printf("Inode number: %ld\n", (long)sb.st_ino);
  printf("File type: ");
  switch (sb.st_mode & S_IFMT) {
  case S_IFBLK:
    printf("block device\n");
    break;
  case S_IFCHR:
    printf("character device\n");
    break;
  case S_IFDIR:
    printf("directory\n");
    break;
  case S_IFIFO:
    printf("FIFO/pipe\n");
    break;
  case S_IFLNK:
    printf("symlink\n");
    break;
  case S_IFREG:
    printf("regular file\n");
    break;
  case S_IFSOCK:
    printf("socket\n");
    break;
  default:
    printf("unknown?\n");
    break;
  }
  printf("Mode: %lo (octal)\n", (unsigned long)sb.st_mode);
  printf("Link count: %ld\n", (long)sb.st_nlink);
  printf("User ID: %ld\n" , (long)sb.st_uid);
  printf("Group ID: %ld\n", (long)sb.st_gid);
  printf("File size: %lld bytes\n", (long long)sb.st_size);
  printf("Last status change: %s", ctime(&sb.st_ctime));
  printf("Last file access: %s", ctime(&sb.st_atime));
  printf("Last file modification: %s", ctime(&sb.st_mtime));

  
  mq_close(mqid);

  return 0;
}
