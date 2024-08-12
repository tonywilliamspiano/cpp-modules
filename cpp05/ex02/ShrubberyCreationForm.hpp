/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:16:23 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/12 17:13:11 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>
# include "colors.hpp"

class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &oldInstance);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &oldInstance);
    ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat &executor) const;
    void beSigned(const Bureaucrat &signer);
};

#endif