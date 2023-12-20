/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 17:38:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <iomanip>
# include <list>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <queue>
# include <cmath>
# include <array>
# include <random>
# include <ctgmath>

using namespace std;

# include "./utils.hpp"
# include "./color.hpp"
# include "./class/Data.hpp"
# include "./class/Stock.hpp"

void	game_loop(Data &data, Stock &stock);
void	instruction_move(u_tuple pos, bool light);
void	instruction_wait(bool light);
u_tuple	choice_pos(Data &data, Stock &stock);
bool	choice_light(Data &data);
string	enum_to_str(e_zone token);

#endif
