/**
\file
\brief Заголовочный файл реализации класса Контроллера приложения

Контроллер является основным координатором приложения и хранителем общих ресурсов. 
При этом GUI должен обеспечивать первичную обработку сигналов и 
простейших алгоритмов (например, вывод окна для получения данных)
самостоятельно.
*/
#ifndef GVEDITOR_CONTROLLER_H_
#define GVEDITOR_CONTROLLER_H_

#include <memory>
#include <vector>
#include <filesystem>
#include "gveditor_igui.h"
#include "gveditor_doc.h"
#include "gveditor_iobj.h"


namespace gvedt
{
    
    class controller
    {
    private:
        controller() = default;
        controller(const controller &arg) = delete;
        controller &operator=(const controller &) = delete;
        controller &operator=(controller &&) = delete;
        controller(controller &&arg) = delete;

        ~controller() = default;

        bool init_good = false;
        bool exit = false; 
    protected:
        std::shared_ptr<igui> sp_gui;
        std::shared_ptr<cl_window> sp_main_window;
        std::shared_ptr<cl_window> sp_doc_window;
        std::shared_ptr<doc> sp_doc;
        std::shared_ptr<iobj> sp_object;
        
    public:
        static controller &ref()
        {
            static controller instance;
            return instance;
        }

        void init(int argc, char const ** argv);
        void init_gui(std::shared_ptr<igui> spgui);
        std::shared_ptr<igui> get_gui();
        void close_app();
        bool app_exit() const;
        void new_document(std::string document_name);
        void import_file();
        void export_file();
        void new_shape(gvedt::obj_types shape_type);
        void delete_shape();
        void select_shape(int id);
        void refresh_doc_window();
        std::vector<long> context_data = {0,0,0};
        std::vector<std::string> context_text{{""},{""},{""}};

    };

} // namespace gvedt

#endif /* GVEDITOR_CONTROLLER_H_ */

