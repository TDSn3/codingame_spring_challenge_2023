/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 16:16:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int	wich_connected(Data &stock_data, int origin, int neighbor)
{
	if (stock_data.conected_to_base[origin])
		return (origin);
	return(neighbor);
}

int	which_not_connected(Data &stock_data, int origin, int neighbor)
{
	if (!stock_data.conected_to_base[origin])
		return (origin);
	return(neighbor);
}

std::vector<int>	assign_power_until_base(Data &stock_data, int neighbor, int index_base)
{
	std::pair<int, std::vector<int> >	path_to_base;

	path_to_base = find_next_base(stock_data, neighbor, 30, index_base);

	// Affichage les beacons
	for (size_t i = 0; i < path_to_base.second.size(); i++)
	{
		stock_data.power_cell[path_to_base.second[i]] += 1;
		cerr << std::setw(3) << path_to_base.second[i] << " │";
	}
	cerr << endl;

	// Affichage le power des beacons
	for (size_t i = 0; i < path_to_base.second.size(); i++)
	{
		cerr << std::setw(3) << stock_data.power_cell[path_to_base.second[i]] << " │";
	}
	cerr << endl;
	return (path_to_base.second);
}

int	my_line(Data &stock_data, int origin, int neighbor, int index_base)
{	
	std::vector<int>	path;
	int					power_prio;

	// assigne priority cell
	path = find_path_origin_neighbor(stock_data, origin, neighbor, 10);

	stock_data.total_power_beacon = 0;
	for (int i = 0; i < stock_data.number_of_cells; i++)
		if (stock_data.beacon_this_loop[i])
			stock_data.total_power_beacon += stock_data.power_cell[i] * stock_data.priority_cell[i];

	if (stock_data.total_power_beacon + ((path.size() - 1) * 4) > (unsigned long int) stock_data.total_ants)
		return (1);

	path = assign_power_until_base(stock_data, neighbor, index_base);
	for (long long int i = path.size() - 1; i > -1; i--)
	{
//		power_prio = stock_data.power_cell[path[i]] * stock_data.priority_cell[path[i]];
		power_prio = stock_data.power_cell[path[i]];
		cout << "BEACON" << " " << path[i] << " " << power_prio << ";";

		if (!stock_data.beacon_this_loop[path[i]])
			stock_data.beacon++;
		stock_data.beacon_this_loop[path[i]] = 1;
	}
	cerr <<  endl;

	stock_data.conected_to_base[neighbor] = 1;
	stock_data.conected_to_base[origin] = 1;
	stock_data.conexions[origin].push_back(neighbor);
	stock_data.total_power_beacon = 0;
	return (0);
}
