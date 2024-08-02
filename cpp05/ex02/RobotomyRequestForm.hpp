/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:09 by awilliam          #+#    #+#             */
/*   Updated: 2023/07/24 12:21:47 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include "colors.hpp"

class RobotomyRequestForm : public AForm {
    private:
        const std::string _target;

    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& oldInstance);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& oldInstance);

		virtual void	execute(const Bureaucrat& executor) const;
    	void 			beSigned(const Bureaucrat& signer);
};

#endif