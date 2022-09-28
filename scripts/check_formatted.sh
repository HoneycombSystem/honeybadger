if [ -n "$(git status --porcelain)" ]; then
  echo "there are changes";
  exit 1;
else
  echo "no changes";
  exit 0;
fi