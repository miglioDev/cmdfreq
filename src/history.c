//history.c


int history_read_file(const char *path)
{
	FILE *fp;
	char buffer[512];
	
	fp = fopen(path, "r"); 
	if(fp == NULL) return -1;
	else 
  {
	  while(fgets(buffer, 512, fp) != NULL)
	  {
	     //add substring rsrc 
	  }
  }
	
	
	fclose(fp);
	
	return 0;
}
