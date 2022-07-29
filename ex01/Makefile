CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MD -g
NAME = span
SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)

#%.o : %.cc
#	$(CXX) $(CXXFLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean :
	rm -f $(OBJS)
	rm -f $(OBJS:.o=.d)

fclean :
	rm -f $(OBJS)
	rm -f $(OBJS:.o=.d)
	rm -f $(NAME)
re :
	rm -f $(OBJS)
	rm -f $(OBJS:.o=.d)
	rm -f $(NAME)
	make $(NAME)

.PHONY : all clean fclean re

-include $(OBJS:.o=.d)
