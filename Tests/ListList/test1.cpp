class List;
struct Node 
{
	    char sym;
	        Node *next;
		    List *lst;
};
class List
{
	public:
		    List(){head = 0; size = 0;}
		        int size;
			    Node *head;
			        void add(const char *str)
					    {
						            if(*str == 0)
								            {
										                return;
												        }
							            if(!head)
									            {
											                head = new Node;
													            size = 1;
														                head->sym = *str;
																            head->next = 0;
																	                head->lst = new List;
																			            head->lst->add(++str);
																				                return;
																						        }
								            Node *tmp = head;
									            while(tmp)
											            {
													                if(tmp->sym == *str)
																            {
																		                    tmp->lst->add(++str);
																				                    size++;
																						                    return;
																								                }
															            if(tmp->next == 0)
																	                {
																				                tmp->next = new Node;
																						                size++;
																								                tmp->next->sym = *str;
																										                tmp->next->next = 0;
																												                tmp->next->lst = new List;
																														                tmp->next->lst->add(++str);
																																                return;
																																		            }
																                tmp = tmp->next;
																		        }
										        }
				    bool del(const char * str)
					        {
							        if(*str == 0)
									            return true;
								        if(!head)
										            return false;
									        if(head->sym == *str)
											        {
													            bool res = head->lst->del(++str);
														                if(res)
																	            {
																			                    if(head->lst->size == 1)
																						                    {
																									                        delete head->lst;
																												                    Node *tmp = head->next;
																														                        delete head;
																																	                    head = tmp;
																																			                    }
																					                    else
																								                        head->lst->size--;
																							                }
																            return res;
																	            }

										        Node *tmp = head;
											        while(tmp->next)
													        {
															            if(tmp->next->sym == *str)
																	                {
																				                bool res = tmp->next->lst->del(++str);
																						                if(res)
																									                {
																												                    if(tmp->next->lst->size == 1)
																															                        {
																																			                        delete tmp->next->lst;
																																						                        Node *tmp2 = tmp->next;
																																									                        tmp->next = tmp->next->next;
																																												                        delete tmp2;
																																															                    }
																														                        else
																																		                        tmp->next->lst->size--;
																																	                    
																																	                }
																								                return res;
																										            }
																                tmp = tmp->next;
																		        }
												        return false;
													    }
				        int find(const char *str)
						    {
							            if(*str == 0)
									            {
											                return size;
													        }
								                
								            Node *tmp = head;
									            while(tmp)
											            {
													                if(tmp->sym == *str)
																            {
																		                    if(str[1] == 0)
																					                    {
																								                        return size;
																											                }
																				                        
																				                    else
																							                        return tmp->lst->find(++str);
																						                }
															            
															            tmp = tmp->next;
																            }
										            return 0;
											        }
};
List *lst  = 0;
void init(){lst = new List();}
void add(const char *email){lst->add(email);}
void del(const char *email){lst->del(email);}
int find(const char *prefix)
{
	    return lst->find(prefix);
}

