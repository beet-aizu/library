(require 'flymake)

(defun flymake-cc-init ()
  (let* ((temp-file   (flymake-init-create-temp-buffer-copy
                       'flymake-create-temp-inplace))
         (local-file  (file-relative-name
                       temp-file
                       (file-name-directory buffer-file-name))))
    (list "g++" (list "-std=c++0x" "-Wall" "-Wextra" "-fsyntax-only" local-file))))

(push '("\\.\\(cc\\|cpp\\|cxx\\|h\\|hpp\\)$" flymake-cc-init) flymake-allowed-file-name-masks)

(add-hook 'c++-mode-hook
          '(lambda ()
             (flymake-mode t)))

(global-set-key "\C-z" 'undo)
(global-set-key "\C-r" 'query-replace)

(setq inhibit-startup-message t)

(auto-insert-mode)
(setq auto-insert-directory "~/.emacs.d/insert/")
(define-auto-insert "\\.cpp$" "t.cpp")
(define-auto-insert "\\.c$" "t.c")
(define-auto-insert "\\.java$" "t.java")

(setq-default tab-width 2 indent-tabs-mode nil)
