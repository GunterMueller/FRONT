#include <elf.h>
#include <libelf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "graph.h"

typedef void (*on_symbol_handler)(Elf32_Sym symbol, char *symbol_name);

static void
record_symbol_info (unsigned id, char *name)
{
  node_t *nd;

  nd = node_find (id);
  if(nd) nd->name = strdup (name);
}

static void
scan_elf(Elf *elf)
{
  Elf32_Ehdr *hdr = elf32_getehdr(elf);
  Elf_Scn *scn = elf_getscn(elf, hdr->e_shstrndx);
  unsigned int i;
  Elf_Data *symdata;
  Elf_Scn *strscn;
  Elf_Data *strdata;
  Elf32_Sym *syms;


  while ( (scn = elf_nextscn(elf, scn)) ) {
    Elf32_Shdr *shdr = elf32_getshdr(scn);

    if (shdr->sh_type != SHT_SYMTAB) continue;
    
    symdata = elf_getdata (scn, NULL);
    strscn = elf_getscn (elf, shdr->sh_link);
    strdata = elf_getdata (strscn, NULL);
    syms = symdata->d_buf;
    
    assert (symdata->d_size % sizeof(Elf32_Sym) == 0);
      
    for (i = 0; i < symdata->d_size / sizeof(Elf32_Sym); i++) {
      char *nameptr = (char *) strdata->d_buf + syms[i].st_name;
      if (ELF32_ST_TYPE(syms[i].st_info) != STT_FUNC) continue;
      
      record_symbol_info(syms[i].st_value, nameptr);
    }
  }
}

int
scan_binary(char *program)
{
  int elffd;
  Elf_Cmd cmd;
  Elf *arf, *elf;
  
  if (!program) return 0;

  elffd = open(program, O_RDONLY);
    
  if (elffd == -1) return 0;
  if (elf_version(EV_CURRENT) == EV_NONE) return 0;
  
  cmd = ELF_C_READ;

  arf = elf_begin(elffd, cmd, NULL);

  while ( (elf = elf_begin(elffd, cmd, arf)) != 0) {
    if (elf32_getehdr(elf) != 0) {
      scan_elf (elf);
    }
    cmd = elf_next(elf);
    elf_end(elf);
  }
  elf_end(arf);
  return 1;
}
