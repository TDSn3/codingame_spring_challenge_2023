/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/26 18:14:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

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

class Data
{
public:

	Data(void);
	Data(const Data &src);
	~Data(void);

	int									my_base_index;
	int									number_of_cells;
	int									total_ants;
	int									max_dist;
	std::vector<int>					res_by_dist;
	std::vector<int>					egg_by_dist;
	std::vector<std::vector<int> >		conexions;
	std::map<int, std::vector<int> >	data_of_cells;
	std::map<int, std::vector<int> >	dof_short_by_dist; // dof = data_of_cells

protected:

private:

};

#endif
