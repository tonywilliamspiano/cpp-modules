/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:21:47 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/12 17:12:23 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>
# include "colors.hpp"

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &oldInstance);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &oldInstance);
    ~RobotomyRequestForm();

    virtual void execute(const Bureaucrat &executor) const;
    void beSigned(const Bureaucrat &signer);
};

#endif